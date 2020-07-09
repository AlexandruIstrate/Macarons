#include "CommandParser.h"

#include <clipp.h>

#define REQUIRED_GROUP(id, val, var, docs) ((required(id) & value(val).call([&](std::string v){ var = v; })) % docs)

namespace Sandbox
{
	using namespace clipp;

	CommandParser::CommandParser()
	{
		Initialize();
	}

	CommandParser::~CommandParser()
	{
	}

	void CommandParser::Parse(int argc, char* argv[]) const
	{
		OutputWriter writer(m_Cli);

		if (!parse(argc, argv, *m_Cli))
		{
			m_HelpCallback(m_Options, writer);
			return;
		}

		if (m_Options.DisplayHelp)
		{
			m_HelpCallback(m_Options, writer);
			return;
		}
		else if (m_Options.DisplayVersion)
		{
			m_VersionCallback(m_Options, writer);
			return;
		}

		m_ExecutionCallback(m_Options, writer);
	}

	void CommandParser::Initialize()
	{
		group* cli = new group(
			value("output path", m_Options.OutputPath),
			REQUIRED_GROUP("-f", "file", m_Options.FilePath, "Use a file for version information") | REQUIRED_GROUP("-r", "repo", m_Options.RepoPath, "Use a Git repository for version information"),
			option("-c", "--config").call([&](std:: string c) { m_Options.ConfigPath = c; }) % "Config file",
			option("-v", "--version").set(m_Options.DisplayVersion) % "Print the app version and exit",
			option("-h", "--help").set(m_Options.DisplayHelp) % "Print this help page and exit"
		);

		m_Cli.reset(cli);
	}
}