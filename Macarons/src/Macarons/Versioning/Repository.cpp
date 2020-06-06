#include "mrpch.h"
#include "Repository.h"

#include <git2.h>

namespace Macarons
{
	Repository::Repository(const std::string& path) : m_Path{ path }
	{
		Init();
	}

	std::vector<Branch> Repository::GetBranches() const
	{
		std::vector<Branch> result;

		git_branch_iterator* it;

		if (!git_branch_iterator_new(&it, m_Repository, GIT_BRANCH_LOCAL))
		{
			git_reference* ref;
			git_branch_t type;

			while (!git_branch_next(&ref, &type, it))
			{
				//result.push_back(Branch());
				git_reference_free(ref);
			}

			git_branch_iterator_free(it);
		}

		return result;
	}

	const Branch& Repository::GetActiveBranch() const
	{
		// TODO: Fix this
		Branch b("Test");
		return b;
	}

	void Repository::Init()
	{
		// Initialize the library
		git_libgit2_init();

		// Initialize the repository
		int result = git_repository_open(&m_Repository, m_Path.c_str());
		MR_CORE_ASSERT(result, "Cannot open repository")
	}

	void Repository::Shutdown()
	{
		// Release the repository
		git_repository_free(m_Repository);

		// Shutdown the library
		git_libgit2_shutdown();
	}
}