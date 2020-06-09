#include "Macarons.h"

int main()
{
	using namespace Macarons;

	// TODO: Move to the core
	Log::Init();

	Repository repo("Some path");
	
	for (const Branch& branch : repo.GetBranches(BranchType::Remote))
	{
		//MR_INFO("Branch is {0}; Is active: {1}; Is tracking remote {2}", branch.GetName(), branch.IsActive(), branch.IsTrackingRemote());

		for (const Commit& commit : branch.GetCommits())
		{
			MR_INFO("Commit {0}", commit.GetMessage());
		}
	}
}