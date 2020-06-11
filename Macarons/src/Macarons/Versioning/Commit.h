#pragma once

#include "mrpch.h"

#include "Branch.h"
#include "Tag.h"

#include <chrono>

struct git_commit;

namespace Macarons
{
	class Commit
	{
	private:
		friend class Branch;

	private:
		Commit(git_commit* commit, const Branch* branch);

	public:
		Commit(Commit&&) noexcept;
		~Commit();

		GitUser GetAuthor() const;
		std::time_t GetCommitDate() const;
		std::string GetMessage() const;
		std::string GetSummary() const;

		std::vector<Tag> GetTags() const;
		Tag CreateTag(const std::string& name, const std::string& message, const GitUser& tagger);
		void DeleteTag(const Tag& tag);

	private:
		git_commit* m_Commit;
		const Branch* m_Branch;
	};
}
