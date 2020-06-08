#include "Macarons.h"

int main()
{
	using namespace Macarons;

	// TODO: Move to the core
	Log::Init();

	Repository repo("Some path");
	
	for (const Branch& branch : repo.GetBranches(BranchType::All))
	{
		MR_INFO("Branch is {0}", branch.GetName());
	}
}