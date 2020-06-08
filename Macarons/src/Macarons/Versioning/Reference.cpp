#include "mrpch.h"
#include "Reference.h"

#include <git2.h>

namespace Macarons
{
	Reference::Reference(git_reference* ref) : m_Reference{ ref }
	{
	}

	Reference::Reference(Reference&& other) noexcept
	{
		m_Reference = std::move(other.m_Reference);
		other.m_Reference = nullptr;
	}

	Reference::~Reference()
	{
		git_reference_free(m_Reference);
	}

	std::string Reference::GetName() const
	{
		return std::string(git_reference_name(m_Reference));
	}

	ReferenceType Reference::GetReferenceType() const
	{
		switch (git_reference_type(m_Reference))
		{
		case GIT_REFERENCE_INVALID:
			return ReferenceType::Invalid;

		case GIT_REFERENCE_DIRECT:
			return ReferenceType::Direct;

		case GIT_REFERENCE_SYMBOLIC:
			return ReferenceType::Symbolic;

		case GIT_REFERENCE_ALL:
			return ReferenceType::All;

		default:
			MR_ASSERT(false, "Reference type does not exist");
		}
	}
}