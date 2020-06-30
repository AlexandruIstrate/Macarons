#include "Macarons.h"

int main()
{
	using namespace Macarons;

	// TODO: Move to the core
	Log::Init();

	Repository repo("Path here");
	
	for (const Branch& branch : repo.GetBranches(BranchType::Remote))
	{
		auto upstream = branch.GetUpstream();
		const std::string& name = upstream.has_value() ? upstream->GetDisplayName() : "Not Available";

		MR_INFO("---------- Branch {0}; Active {1}; Upstream {2} ----------\n", branch.GetName(), branch.IsActive(), name);

		for (const Commit& commit : branch.GetCommits())
		{
			//MR_INFO("Commit[{0}] - {1}", commit.GetCommitDate(), commit.GetMessage());

			for (const Tag& tag : commit.GetTags())
			{
				MR_INFO("Tag {0}; {1} ({2}, {3})", tag.GetName(), tag.GetMessage(), tag.GetTagger().Name, tag.GetTagger().Email);
			}
		}
	}

	GitFlowCompiler comp(repo);
	SemanticVersion version = comp.GetVersion();

	MR_INFO("Repository is at version {0}.{1}.{2}", version.GetMajor(), version.GetMinor(), version.GetPatch());
}