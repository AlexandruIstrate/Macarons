#pragma once

#include "VersionCompiler.h"
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

	class GitFlowCompiler : public VersionCompiler<int>
	{
	public:
		GitFlowCompiler(const Repository& repository);

		inline const Repository& GetRepository() const { return m_Repository; }
		inline void SetRepository(const Repository& repo) { m_Repository = repo; }

		virtual int GetMajorVersion() const override;
		virtual int GetMinorVersion() const override;
		virtual int GetPatchVersion() const override;

	private:
		static GitFlowBranchType GetBranchType(const Branch& branch);

	private:
		Repository m_Repository;
	};
}