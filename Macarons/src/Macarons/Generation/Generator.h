#pragma once

#include "mrpch.h"

namespace Macarons
{
	enum VersionKind
	{
		None = 0,
		VersionMajorMinorPatch		= BIT(0),
		VersionShort				= BIT(1),
		VersionLong					= BIT(2),
		VersionLocalisedDisplay		= BIT(3),
	};

	class Generator
	{
	public:
		virtual ~Generator() = default;

		inline int GetGenerationFlags() const { return m_GenerationFlags; }
		inline void SetGenerationFlags(int flags) { m_GenerationFlags = flags; }

		inline bool HasFlag(VersionKind flag) const
		{
			return GetGenerationFlags() & flag;
		}

		virtual std::string GetName() const = 0;
		virtual std::string GetDisplayName() const = 0;
		virtual std::unordered_set<std::string> GetSupportedFileExtensions() const = 0;

		virtual std::string Generate() = 0;

	protected:
		int m_GenerationFlags;
	};
}