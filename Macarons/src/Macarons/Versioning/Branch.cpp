#include "mrpch.h"
#include "Branch.h"

#include <git2.h>

namespace Macarons
{
	Branch::Branch(git_reference* ref) : Reference{ref}
	{
		
	}

	bool Branch::IsActiveBranch() const
	{
		return git_branch_is_head(m_Reference);
	}

	bool Branch::IsTrackingRemote() const
	{
		return false;
	}

	Branch Branch::GetRemote() const
	{
		return Branch(nullptr);
	}
}