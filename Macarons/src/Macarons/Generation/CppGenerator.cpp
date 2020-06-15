#include "mrpch.h"
#include "CppGenerator.h"

namespace Macarons
{
	/*CppGenerator::CppGenerator(const Repository& repo) : m_Repository{ repo }
	{
	}*/

	std::string CppGenerator::GetGeneratorName() const
	{
		return "cpp";
	}

	std::string CppGenerator::GetGeneratorDisplayName() const
	{
		return "C++ Header Generator";
	}

	std::unordered_set<std::string> CppGenerator::GetSupportedFileExtensions() const
	{
		return { "h", "hpp" };
	}

	std::string CppGenerator::Generate()
	{
		return std::string();
	}
}