#pragma once

#include "VersionCompiler.h"
#include "Macarons/Versioning/Repository.h"

namespace Macarons
{
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
		Repository m_Repository;
	};
}