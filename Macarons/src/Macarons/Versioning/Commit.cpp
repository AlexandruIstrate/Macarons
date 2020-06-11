#include "mrpch.h"
#include "Commit.h"

#include <git2.h>

namespace Macarons
{
	Commit::Commit(git_commit* commit, const Branch* branch) : m_Commit{ commit }, m_Branch{ branch }
	{
	}

	Commit::Commit(Commit&& other) noexcept
	{
		m_Commit = std::move(other.m_Commit);
		m_Branch = std::move(other.m_Branch);

		other.m_Commit = nullptr;
		other.m_Branch = nullptr;
	}

	Commit::~Commit()
	{
		git_commit_free(m_Commit);
	}

	Macarons::GitUser Commit::GetAuthor() const
	{
		const git_signature* signature = git_commit_author(m_Commit);

		GitUser author;
		author.Name = signature->name;
		author.Email = signature->email;

		return author;
	}

	std::time_t Commit::GetCommitDate() const
	{
		return git_commit_time(m_Commit);
	}

	std::string Commit::GetMessage() const
	{
		return git_commit_message(m_Commit);
	}

	std::string Commit::GetSummary() const
	{
		return git_commit_summary(m_Commit);
	}

	std::vector<Tag> Commit::GetTags() const
	{
		std::vector<Tag> result;

		git_reference_iterator* iter;
		git_reference_iterator_glob_new(&iter, m_Branch->GetRepository().m_Repo, "refs/tags/*");

		git_reference* ref;

		while (!git_reference_next(&ref, iter))
		{
			const git_oid* oid = git_reference_target(ref);

			git_tag* tag;
			git_tag_lookup(&tag, m_Branch->GetRepository().m_Repo, oid);

			// Create the Tag and add it to the vector
			result.push_back(Tag(tag));

			git_reference_free(ref);
		}

		git_reference_iterator_free(iter);

		return result;
	}

	Tag Commit::CreateTag(const std::string& name, const std::string& message, const GitUser& tagger)
	{
		/* Sign the commit */
		git_signature* sig;
		git_signature_now(&sig, tagger.Name.c_str(), tagger.Email.c_str());

		/* Create the tag */
		git_oid annotation_id;
		git_tag_create(&annotation_id, m_Branch->GetRepository().m_Repo, name.c_str(), nullptr, sig, message.c_str(), /* force */ true);

		git_signature_free(sig);

		return Tag(nullptr);
	}

	void Commit::DeleteTag(const Tag& tag)
	{
		int error = git_tag_delete(m_Branch->GetRepository().m_Repo, tag.GetName().c_str());
		MR_CORE_ASSERT(error == GIT_ERROR_NONE, "Could not delete tag");
	}
}