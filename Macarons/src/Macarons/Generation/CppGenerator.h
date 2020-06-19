#pragma once

#include "Generator.h"
#include "VersionCompiler.h"

namespace Macarons
{
	class CppGenerator : public Generator
	{
	public:
		CppGenerator(const VersionCompiler<int>& versionCompiler);

		virtual std::string GetName() const override;
		virtual std::string GetDisplayName() const override;
		virtual std::unordered_set<std::string> GetSupportedFileExtensions() const override;

		virtual std::string Generate() override;
	};
}
