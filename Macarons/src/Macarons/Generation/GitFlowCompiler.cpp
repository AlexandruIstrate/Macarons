#include "mrpch.h"
#include "GitFlowCompiler.h"

#include <regex>

namespace Macarons
{
	GitFlowCompiler::GitFlowCompiler(const Repository& repository) : m_Repository{ repository }
	{
	}

	int GitFlowCompiler::GetMajorVersion() const
	{
		const Branch& currentBranch = m_Repository.GetActiveBranch();

		GitFlowBranchType type = GetBranchType(currentBranch);
		MR_CORE_INFO("Active branch type ({0}) {1}", currentBranch.GetDisplayName(), type);

		throw std::logic_error("The method or operation is not implemented.");
	}

	int GitFlowCompiler::GetMinorVersion() const
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	int GitFlowCompiler::GetPatchVersion() const
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	GitFlowBranchType GitFlowCompiler::GetBranchType(const Branch& branch)
	{
		const std::string& branchName = branch.GetName();

		// Master
		std::regex master{ "refs/heads/master" };

		if (std::regex_match(branchName.begin(), branchName.end(), master))
		{
			return GitFlowBranchType::Master;
		}

		// Develop
		std::regex develop { "refs/heads/develop" };

		if (std::regex_match(branchName.begin(), branchName.end(), develop))
		{
			return GitFlowBranchType::Develop;
		}

		// Feature
		std::regex feature{ "refs/heads/feature/[aA-zZ0-9]*" };

		if (std::regex_match(branchName.begin(), branchName.end(), feature))
		{
			return GitFlowBranchType::Feature;
		}

		// Release
		std::regex release{ "refs/heads/release/[aA-zZ0-9]*" };

		if (std::regex_match(branchName.begin(), branchName.end(), release))
		{
			return GitFlowBranchType::Release;
		}

		return GitFlowBranchType::Default;
	}
}