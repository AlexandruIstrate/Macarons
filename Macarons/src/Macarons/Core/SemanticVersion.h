#pragma once

#include "mrpch.h"

namespace Macarons
{
	enum class VersionField
	{
		Major,
		Minor,
		Patch
	};

	class SemanticVersion
	{
	public:
		SemanticVersion(int major, int minor, int patch);
		SemanticVersion(const std::string& versionString);

		inline int GetMajor() const { return m_Major; }
		inline void SetMajor(int major) { m_Major = major; }

		inline int GetMinor() const { return m_Minor; }
		inline void SetMinor(int minor) { m_Major = minor; }

		inline int GetPatch() const { return m_Patch; }
		inline void SetPatch(int patch) { m_Major = patch; }

		void Increment(VersionField strategy);

		std::string ToString() const;

		bool operator<(const SemanticVersion& other) const;
		bool operator>(const SemanticVersion& other) const;

	public:
		friend bool operator==(const SemanticVersion& lhs, const SemanticVersion& rhs);
		friend bool operator!=(const SemanticVersion& lhs, const SemanticVersion& rhs);

	private:
		int m_Major;
		int m_Minor;
		int m_Patch;
	};

	bool operator==(const SemanticVersion& lhs, const SemanticVersion& rhs);
	bool operator!=(const SemanticVersion& lhs, const SemanticVersion& rhs);
}
