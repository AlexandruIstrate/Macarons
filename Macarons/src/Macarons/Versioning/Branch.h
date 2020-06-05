#pragma once

#include "mrpch.h"

namespace Macarons
{
	class Branch
	{
	private:
		friend class Repository;

	private:
		Branch(const std::string& name);

	public:
		Branch(const Branch&) = delete;

		inline const std::string& GetName() const { return m_Name; }

		void GetCommits();
		void GetLatestCommit();
		int GetCommitCount();

	private:
		std::string m_Name;
	};
}
