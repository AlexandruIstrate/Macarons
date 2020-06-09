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

	std::time_t Commit::GetCommitDate()
	{
		/*const git_signature* signature = git_commit_author(m_Commit);
		return signature->when().time;*/
		return time_t();
	}

	std::string Commit::GetMessage() const
	{
		return git_commit_message(m_Commit);
	}

	std::string Commit::GetSummary() const
	{
		return git_commit_summary(m_Commit);
	}

}