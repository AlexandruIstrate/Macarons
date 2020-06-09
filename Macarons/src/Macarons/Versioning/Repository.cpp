#include "mrpch.h"
#include "Repository.h"

#include <git2.h>

namespace Macarons
{
	BranchType GetBranchType(git_branch_t type)
	{
		switch (type)
		{
		case GIT_BRANCH_LOCAL:
			return BranchType::Local;

		case GIT_BRANCH_REMOTE:
			return BranchType::Remote;

		default:
			MR_CORE_ASSERT(false, "Unsuported branch type")
		}
	}

	Repository::Repository(const std::string& path) : m_Repo{ nullptr }
	{
		Init(path);
	}

	Repository::~Repository()
	{
		git_repository_free(m_Repo);

		// Shutdown the library
		git_libgit2_shutdown();
	}

	std::string Repository::GetPath() const
	{
		return git_repository_path(m_Repo);
	}

	std::string Repository::GetWorkingDirectory() const
	{
		return git_repository_workdir(m_Repo);
	}

	std::vector<Branch> Repository::GetBranches(BranchType branchType) const
	{
		std::vector<Branch> res;

		git_branch_iterator* it;

		if (!git_branch_iterator_new(&it, m_Repo, GIT_BRANCH_LOCAL))
		{
			git_reference* ref;
			git_branch_t type;

			while (!git_branch_next(&ref, &type, it))
			{
				res.push_back(Branch(ref, GetBranchType(type), *this));
			}

			git_branch_iterator_free(it);
		}

		return res;
	}

	Macarons::Branch Repository::GetActiveBranch() const
	{
		git_branch_iterator* it;

		if (!git_branch_iterator_new(&it, m_Repo, GIT_BRANCH_LOCAL))
		{
			git_reference* ref;
			git_branch_t type;

			while (!git_branch_next(&ref, &type, it))
			{
				// Check if the branch is the current HEAD.
				if (git_branch_is_head(ref))
				{
					git_branch_iterator_free(it);
					return Branch(ref, GetBranchType(type), *this);
				}
			}

			git_branch_iterator_free(it);
		}

		MR_ASSERT(false, "Could not retrieve HEAD branch");
	}

	Branch Repository::CreateBranch(const std::string& name)
	{
		git_reference* ref;

		int error = git_branch_create(&ref, m_Repo, name.c_str(), nullptr, false);
		MR_ASSERT(error == GIT_ERROR_NONE, "Could not create branch");

		return Branch(ref, BranchType::Local, *this);
	}

	void Repository::DeleteBranch(const Branch& branch)
	{
		int error = git_branch_delete(branch.m_Reference);
		MR_ASSERT(error == GIT_ERROR_NONE, "Could not delete branch");
	}

	void Repository::Init(const std::string& path)
	{
		// Initialize the library
		git_libgit2_init();

		int error = git_repository_open(&m_Repo, path.c_str());
		MR_ASSERT(error == GIT_ERROR_NONE, "Could not open repository");
	}
}