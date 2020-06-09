#pragma once

#include "mrpch.h"

#include "Branch.h"

#include <chrono>

struct git_commit;

namespace Macarons
{
	class Commit
	{
	private:
		friend class Branch;

	private:
		Commit(git_commit* commit);

	public:
		Commit(Commit&&) noexcept;
		~Commit();

		GitUser GetAuthor() const;
		std::time_t GetCommitDate();
		std::string GetMessage() const;
		std::string GetSummary() const;

	private:
		git_commit* m_Commit;
	};
}
