#include "CommandParser.h"

#include <clipp.h>

#define REQUIRED_GROUP(id, val, var, docs) ((required(id) & value(val, var)) % docs)

namespace Sandbox
{
	using namespace clipp;

	CommandParser::CommandParser()
	{
		Initialize();
	}

	void CommandParser::Parse(int argc, char* argv[]) const
	{
		if (!parse(argc, argv, *m_Cli))
		{
			m_HelpCallback(m_Options);
			return;
		}

		if (m_Options.DisplayHelp)
		{
			m_HelpCallback(m_Options);
			return;
		}
		else if (m_Options.DisplayVersion)
		{
			m_VersionCallback(m_Options);
			return;
		}

		m_ExecutionCallback(m_Options);
	}

	std::string CommandParser::PrintHelp(const std::string& appName) const
	{
		// Make use of clipp's << operator
		std::stringstream ss;
		ss << make_man_page(*m_Cli, appName);
		return ss.str();
	}

	std::string CommandParser::PrintVersion(const std::string& version, const std::string& appName, const std::string& copyright) const
	{
		std::stringstream ss;
		std::cout << appName << " (" << version << ") " << copyright;
		return ss.str();
	}

	void CommandParser::Initialize()
	{
		std::string file, repo;
		std::string config;

		group* cli = new group(
			value("output path", m_Options.OutputPath),
			REQUIRED_GROUP("-f", "file", file, "Use a file for version information") | REQUIRED_GROUP("-r", "repo", repo, "Use a Git repository for version information"),
			option("-c", "--config").set(config) % "Config file",
			option("-v", "--version").set(m_Options.DisplayVersion) % "Print the app version and exit",
			option("-h", "--help").set(m_Options.DisplayHelp) % "Print this help page and exit"
		);

		m_Cli.reset(cli);
	}
}