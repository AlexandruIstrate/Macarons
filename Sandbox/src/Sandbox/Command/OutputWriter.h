#pragma once

#include <string>
#include <memory>

namespace clipp
{
	class group;
}

namespace Sandbox
{
	class OutputWriter
	{
	public:
		OutputWriter(std::shared_ptr<clipp::group> cli);

		std::string PrintHelp(const std::string& appName) const;
		std::string PrintVersion(const std::string& version, const std::string& appName, const std::string& copyright) const;

	private:
		std::shared_ptr<clipp::group> m_Cli;
	};
}