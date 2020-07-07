#include "mrpch.h"
#include "CppGenerator.h"

namespace Macarons
{
	CppGenerator::CppGenerator(VersionCompiler<SemanticVersion>* versionCompiler) : m_Compiler { versionCompiler }
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
		SemanticVersion version = m_Compiler->GetVersion();

		std::stringstream ss;
		ss << "#pragma once" << '\n';

		if (HasFlag(VersionMajorMinorPatch))
		{
			ss << "#define MACARONS_VER_MAJOR " << version.GetMajor() << '\n';
			ss << "#define MACARONS_VER_MINOR " << version.GetMinor() << '\n';
			ss << "#define MACARONS_VER_PATCH " << version.GetPatch() << '\n';
		}

		if (HasFlag(VersionShort))
		{
			ss << "#define MACARONS_VER_SHORT" << version.ToString() << '\n';
		}

		if (HasFlag(VersionLong))
		{
			ss << "#define MACARONS_VER_LONG" << '\n';
		}

		return ss.str();
	}
}