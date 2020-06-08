#pragma once

#include "mrpch.h"

struct git_reference;

enum class ReferenceType : unsigned int
{
	Invalid = 0,
	Direct,
	Symbolic,
	All = Direct | Symbolic
};

namespace Macarons
{
	class Reference
	{
	public:
		Reference(git_reference* reference);
		Reference(Reference&&) noexcept;

		virtual ~Reference();

		std::string GetName() const;
		ReferenceType GetReferenceType() const;

	protected:
		git_reference* m_Reference;
	};
}
