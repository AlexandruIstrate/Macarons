#include "mrpch.h"
#include "GitFlowCompiler.h"

#include "Macarons/Versioning/Commit.h"

#include <regex>

namespace Macarons
{
	GitFlowCompiler::GitFlowCompiler(Repository* repository) : m_Repository{ repository }
	{
		Initialize();
	}

	SemanticVersion GitFlowCompiler::GetVersion() const
	{
		// Figure out the major version using the master branch
		for (const Commit& commit : m_Master->GetCommits())
		{
			// Get the tags
			std::vector<Tag> tags = commit.GetTags();

			for (const Tag& tag : tags)
			{
				const std::string& tagName = tag.GetName();

				std::regex versionRegex(R"(^(0|[1-9]\d*)\.(0|[1-9]\d*)\.(0|[1-9]\d*)(-[a-zA-Z\d][-a-zA-Z.\d]*)?(\+[a-zA-Z\d][-a-zA-Z.\d]*)?$)");
				std::smatch match;

				if (std::regex_search(tagName.begin(), tagName.end(), match, versionRegex))
				{
					std::string version = match[1];
					return SemanticVersion(1, 0, 0);
				}
			}
		}

		return SemanticVersion(1, 0, 0);
	}

	void GitFlowCompiler::Initialize()
	{
		for (Branch& branch : m_Repository->GetBranches(BranchType::Local))
		{
			switch (GetBranchType(branch))
			{
			case GitFlowBranchType::Master:
				m_Master.emplace(std::move(branch));
				break;

			case GitFlowBranchType::Develop:
				m_Develop.emplace(std::move(branch));
				break;

			case GitFlowBranchType::Feature:
				m_Features.push_back(std::move(branch));
				break;

			default:
				break;
			}
		}

		if (!m_Master.has_value())
		{
			throw std::exception("Master branch does not exist");
		}

		if (!m_Develop.has_value())
		{
			throw std::exception("Develop branch does not exist");
		}
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