#pragma once

#include "VersionCompiler.h"
#include "Macarons/Core/SemanticVersion.h"
#include "Macarons/Versioning/Repository.h"

namespace Macarons
{
	enum class GitFlowBranchType
	{
		Default = 0,
		Master,
		Develop,
		Feature,
		Release
	};

	class GitFlowCompiler : public VersionCompiler<SemanticVersion>
	{
	public:
		GitFlowCompiler(Repository* repository);

		virtual SemanticVersion GetVersion() const override;

	private:
		void Initialize();

	private:
		static GitFlowBranchType GetBranchType(const Branch& branch);

	private:
		std::unique_ptr<Repository> m_Repository;

		std::optional<Branch> m_Master;
		std::optional<Branch> m_Develop;
		std::vector<Branch> m_Features;
	};
}