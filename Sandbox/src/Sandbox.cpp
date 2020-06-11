#include "Macarons.h"

int main()
{
	using namespace Macarons;

	// TODO: Move to the core
	Log::Init();

	Repository repo("Path");
	
	for (const Branch& branch : repo.GetBranches(BranchType::Remote))
	{
		//MR_INFO("---------- Branch {0}; Active {1} ----------\n", branch.GetName(), branch.IsActive());

		for (const Commit& commit : branch.GetCommits())
		{
			//MR_INFO("Commit[{0}] - {1}", commit.GetCommitDate(), commit.GetMessage());

			for (const Tag& tag : commit.GetTags())
			{
				MR_INFO("Tag {0}; {1} ({2}, {3})", tag.GetName(), tag.GetMessage(), tag.GetTagger().Name, tag.GetTagger().Email);
			}
		}
	}
}