#include "OutputWriter.h"

#include <sstream>

#include <clipp.h>

namespace Sandbox
{
	OutputWriter::OutputWriter(std::shared_ptr<clipp::group> cli) : m_Cli{ cli }
	{
	}

	std::string OutputWriter::PrintHelp(const std::string& appName) const
	{
		// Make use of clipp's << operator
		std::stringstream ss;
		ss << clipp::make_man_page(*m_Cli, appName);
		return ss.str();
	}

	std::string OutputWriter::PrintVersion(const std::string& version, const std::string& appName, const std::string& copyright) const
	{
		std::stringstream ss;
		ss << appName << " (" << version << ") " << copyright;
		return ss.str();
	}
}