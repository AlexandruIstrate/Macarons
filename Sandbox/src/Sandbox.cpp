#include "Macarons.h"

int main()
{
	// TODO: Move to the core
	Macarons::Log::Init();

	Macarons::Repository r("D:\\Projects\\C++\\Macarons\\.git");
	//r.GetBranches();

	MR_INFO("Hello World!");
}