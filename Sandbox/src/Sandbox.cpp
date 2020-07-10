#include "Sandbox/Core/Base.h"

#include <fstream>

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
	VersionCompiler<SemanticVersion>* vc;

	if (opts.FilePath)
	{
		// Handle the version file
		vc = new YamlCompiler(opts.FilePath.value());
	}
	else
	{
		// Read the repository
		Repository* repo = new Repository(opts.RepoPath.value());

		// Get the information from the repository
		vc = new GitFlowCompiler(repo);
	}

	// Generate the file
	CppGenerator gen(vc);
	gen.SetGenerationFlags(VersionMajorMinorPatch | VersionLong | VersionShort);

	const std::string& result = gen.Generate();

	std::ofstream file(opts.OutputPath);
	file << result;
	file.flush();
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
