#include "Sandbox/Core/Base.h"

using namespace Macarons;
using namespace Sandbox;

int main(int argc, char* argv[])
{
	// Initialize the log
	Log::Init();

	Sandbox::CommandParser parser;
	parser.SetExecutionCallback([](const CommandLineOptions& opts, const OutputWriter& writer) {
		MR_INFO("Execution success");
	});
	parser.SetHelpCallback([](const CommandLineOptions& opts, const OutputWriter& writer) {
		// Print the synopsis and the usage
		std::cout << writer.PrintHelp("Macarons") << std::endl;
	});
	parser.SetVersionCallback([](const CommandLineOptions& opts, const OutputWriter& writer) {
		// Print the version
		std::cout << writer.PrintVersion("1.0.0", "Macarons", "Copyright Alexandru Istrate 2020") << std::endl;
	});

	parser.Parse(argc, argv);
}