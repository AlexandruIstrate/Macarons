#pragma once

#define NOMINMAX
#include "Macarons.h"

#include "OutputWriter.h"

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
		bool DisplayHelp = false, DisplayVersion = false;
	};

	class CommandParser
	{
	public:
		using CommandCallbackFn = std::function<void(const CommandLineOptions&, const OutputWriter&)>;

	public:
		CommandParser();
		~CommandParser();

		inline void SetExecutionCallback(const CommandCallbackFn& callback) { m_ExecutionCallback = callback; }
		inline void SetHelpCallback(const CommandCallbackFn& callback) { m_HelpCallback = callback; }
		inline void SetVersionCallback(const CommandCallbackFn& callback) { m_VersionCallback = callback; }

		void Parse(int argc, char* argv[]) const;

	private:
		void Initialize();

	private:
		std::shared_ptr<clipp::group> m_Cli;
		CommandLineOptions m_Options;

		CommandCallbackFn m_ExecutionCallback;
		CommandCallbackFn m_HelpCallback;
		CommandCallbackFn m_VersionCallback;
	};
}
