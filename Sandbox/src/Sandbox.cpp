#include "Sandbox/Core/Base.h"

using namespace Macarons;
using namespace Sandbox;

void HandleExecution(const CommandLineOptions& opts, const OutputWriter& writer);
void HandleHelp(const CommandLineOptions& opts, const OutputWriter& writer);
void HandleVersion(const CommandLineOptions& opts, const OutputWriter& writer);

int main(int argc, char* argv[])
{
	// Initialize the log
	Log::Init();

	Sandbox::CommandParser parser;
	parser.SetExecutionCallback(HandleExecution);
	parser.SetHelpCallback(HandleHelp);
	parser.SetVersionCallback(HandleVersion);

	parser.Parse(argc, argv);
}

void HandleExecution(const CommandLineOptions& opts, const OutputWriter& writer)
{
	std::unique_ptr<VersionCompiler<SemanticVersion>> vc;

	if (opts.FilePath)
	{
		// Handle the version file
	}
	else if (opts.RepoPath)
	{
		// Get the information from the repository
	}

	// Generate the file
	CppGenerator gen(vc.get());
	gen.Generate();
}

void HandleHelp(const CommandLineOptions& opts, const OutputWriter& writer)
{
	// Print the synopsis and the usage
	std::cout << writer.PrintHelp("Macarons") << std::endl;
}

void HandleVersion(const CommandLineOptions& opts, const OutputWriter& writer)
{
	// Print the version
	std::cout << writer.PrintVersion("1.0.0", "Macarons", "(c) 2020 Alexandru Istrate. All rights reserved.") << std::endl;
}
