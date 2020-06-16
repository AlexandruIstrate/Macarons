#include "mrpch.h"
#include "CppGenerator.h"

namespace Macarons
{
	CppGenerator::CppGenerator(const Repository& repo) : Generator::Generator(repo)
	{
	}

	std::string CppGenerator::GetName() const
	{
		return "cpp-generator";
	}

	std::string CppGenerator::GetDisplayName() const
	{
		return "C++ Header Generator";
	}

	std::unordered_set<std::string> CppGenerator::GetSupportedFileExtensions() const
	{
		return { "h", "hpp", "hxx" };
	}

	std::string CppGenerator::Generate()
	{
		std::stringstream ss;

		ss << "#pragma once";

		ss << "#define MACARONS_VER_LONG" << '\n';
		ss << "#define MACARONS_VER_SHORT" << '\n';

		ss << "#define MACARONS_VER_MAJOR" << '\n';
		ss << "#define MACARONS_VER_MINOR" << '\n';
		ss << "#define MACARONS_VER_PATCH" << '\n';

		return ss.str();
	}
}