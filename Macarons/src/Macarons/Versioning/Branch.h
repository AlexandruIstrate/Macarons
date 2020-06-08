#pragma once

#include "Reference.h"

//enum git_branch_t;

namespace Macarons
{
	enum class BranchType : unsigned int
	{
		Local = 1,
		Remote,
		All = Local | Remote
	};

	class Branch : public Reference
	{
	public:
		Branch(git_reference* ref);

		bool IsActiveBranch() const;
		bool IsTrackingRemote() const;

		Branch GetRemote() const;

		void CreateCommit(const std::string& author, const std::string& message);
	};
}
