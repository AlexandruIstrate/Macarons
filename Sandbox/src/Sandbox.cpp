#include "Macarons.h"

int main()
{
	using namespace Macarons;

	// TODO: Move to the core
	Log::Init();

	YamlCompiler* compiler = new YamlCompiler("Path here");
	std::unique_ptr<CppGenerator> generator = std::make_unique<CppGenerator>(compiler);

	MR_CORE_INFO("Generated {0}", generator->Generate());
}