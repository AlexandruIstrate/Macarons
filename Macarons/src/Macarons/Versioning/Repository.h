#pragma once

#include "mrpch.h"
#include "Branch.h"

struct git_repository;

namespace Macarons
{
	class Repository
	{
	public:
		Repository(const std::string& path);
		Repository(const Repository&) = delete;

		std::vector<Branch> GetBranches() const;
		const Branch& GetActiveBranch() const;

	private:
		void Init();
		void Shutdown();

	private:
		std::string m_Path;
		git_repository* m_Repository;
	};
}