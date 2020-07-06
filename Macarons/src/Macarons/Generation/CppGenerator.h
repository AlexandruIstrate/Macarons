#pragma once

#include "Generator.h"
#include "VersionCompiler.h"
#include "Macarons/Core/SemanticVersion.h"

namespace Macarons
{
	class CppGenerator : public Generator
	{
	public:
		CppGenerator(VersionCompiler<SemanticVersion>*);

		virtual std::string GetName() const override;
		virtual std::string GetDisplayName() const override;
		virtual std::unordered_set<std::string> GetSupportedFileExtensions() const override;

		virtual std::string Generate() override;

	private:
		std::unique_ptr<VersionCompiler<SemanticVersion>> m_Compiler;
	};
}
