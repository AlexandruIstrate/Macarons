#include "mrpch.h"
#include "Commit.h"

#include <git2.h>

namespace Macarons
{
	Commit::Commit(git_commit* commit) : m_Commit{ commit }
	{
	}

	Commit::Commit(Commit&& other) noexcept
	{
		m_Commit = std::move(other.m_Commit);
		other.m_Commit = nullptr;
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



		return result;
	}

	Tag Commit::CreateTag(const std::string& name, const std::string& message, const GitUser& tagger)
	{
		/* Sign the commit */
		git_signature* sig;
		git_signature_now(&sig, tagger.Name.c_str(), tagger.Email.c_str());

		/* Create the tag */
		git_oid annotation_id;
		git_tag_create(&annotation_id, nullptr, name.c_str(), nullptr, sig, message.c_str(), /* force */ true);

		git_signature_free(sig);

		return Tag(nullptr);
	}

	void Commit::DeleteTag(const Tag& tag)
	{
	}
}