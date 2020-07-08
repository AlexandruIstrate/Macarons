#pragma once

#include "Sandbox/Core/Base.h"

namespace clipp
{
	class group;
}

namespace Sandbox
{
	struct CommandLineOptions
	{
		std::string OutputPath;
		std::optional<std::string> FilePath, RepoPath;
		std::optional<std::string> ConfigPath;
		bool DisplayHelp, DisplayVersion;
	};

	class CommandParser
	{
	public:
		using CommandCallbackFn = std::function<void(const CommandLineOptions&)>;

	public:
		CommandParser();

		inline void SetExecutionCallback(const CommandCallbackFn& callback) { m_ExecutionCallback = callback; }
		inline void SetHelpCallback(const CommandCallbackFn& callback) { m_HelpCallback = callback; }
		inline void SetVersionCallback(const CommandCallbackFn& callback) { m_VersionCallback = callback; }

		void Parse(int argc, char* argv[]) const;

		std::string PrintHelp(const std::string& appName) const;
		std::string PrintVersion(const std::string& version, const std::string& appName, const std::string& copyright) const;

	private:
		void Initialize();

	private:
		std::unique_ptr<clipp::group> m_Cli;
		CommandLineOptions m_Options;

		CommandCallbackFn m_ExecutionCallback;
		CommandCallbackFn m_HelpCallback;
		CommandCallbackFn m_VersionCallback;
	};
}
