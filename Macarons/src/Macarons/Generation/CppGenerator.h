#pragma once

#include "Generator.h"

namespace Macarons
{
	class CppGenerator : public Generator
	{
	public:
		CppGenerator(const Repository& repo);

	public:
		virtual std::string GetName() const override;
		virtual std::string GetDisplayName() const override;
		virtual std::unordered_set<std::string> GetSupportedFileExtensions() const override;

		virtual std::string Generate() override;
	};
}
