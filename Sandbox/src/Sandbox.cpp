#include "Macarons.h"

int main()
{
	using namespace Macarons;

	// TODO: Move to the core
	Log::Init();

	Repository repo("Path here");

	YamlCompiler comp("Path here");
	SemanticVersion version = comp.GetVersion();

	MR_INFO("Repository is at version {0}.{1}.{2}", version.GetMajor(), version.GetMinor(), version.GetPatch());
}