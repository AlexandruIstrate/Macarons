#pragma once

#include "mrpch.h"
#include "Branch.h"

struct git_repository;

namespace Macarons
{
	class Repository
	{
	private:
		friend class Branch;

	public:
		Repository(const std::string& path);
		~Repository();

		std::string GetPath() const;
		std::string GetWorkingDirectory() const;

		std::vector<Branch> GetBranches(BranchType branchType) const;
		Branch GetActiveBranch() const;
		Branch CreateBranch(const std::string& name);
		void DeleteBranch(const Branch& branch);

	private:
		void Init(const std::string& path);

	private:
		git_repository* m_Repo;
	};
}