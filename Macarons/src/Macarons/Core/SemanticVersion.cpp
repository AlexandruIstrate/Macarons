#include "mrpch.h"
#include "SemanticVersion.h"

namespace Macarons
{
	SemanticVersion::SemanticVersion(int major, int minor, int patch) : m_Major{ major }, m_Minor{ minor }, m_Patch{ patch }
	{
	}

	SemanticVersion::SemanticVersion(const std::string& versionString) : m_Major{ 0 }, m_Minor{ 0 }, m_Patch{ 0 }
	{
		std::vector<int> components;

		std::stringstream ss(versionString);
		std::string token;

		while (std::getline(ss, token, '.'))
		{
			components.push_back(atoi(token.c_str()));
		}

		m_Major = components[0];
		m_Minor = components[1];
		m_Patch = components[2];
	}

	void SemanticVersion::Increment(VersionField strategy)
	{
		switch (strategy)
		{
		case VersionField::Major:
			m_Major++;
			break;

		case VersionField::Minor:
			m_Minor++;
			break;

		case VersionField::Patch:
			m_Patch++;
			break;

		default:
			break;
		}
	}

	std::string SemanticVersion::ToString() const
	{
		std::stringstream ss;
		ss << m_Major << "." << m_Minor << "." << m_Patch;
		return ss.str();
	}

	bool SemanticVersion::operator<(const SemanticVersion& other) const
	{
		if (m_Major != other.m_Major)
		{
			if (m_Major < other.m_Major)
			{
				return true;
			}

			return false;
		}

		if (m_Minor != other.m_Minor)
		{
			if (m_Minor < other.m_Minor)
			{
				return true;
			}

			return false;
		}

		if (m_Patch != other.m_Patch)
		{
			if (m_Patch < other.m_Patch)
			{
				return true;
			}

			return false;
		}

		return false;
	}

	bool SemanticVersion::operator>(const SemanticVersion& other) const
	{
		if (m_Major != other.m_Major)
		{
			if (m_Major > other.m_Major)
			{
				return true;
			}

			return false;
		}

		if (m_Minor != other.m_Minor)
		{
			if (m_Minor > other.m_Minor)
			{
				return true;
			}

			return false;
		}

		if (m_Patch != other.m_Patch)
		{
			if (m_Patch > other.m_Patch)
			{
				return true;
			}

			return false;
		}

		return false;
	}

	bool operator==(const SemanticVersion& lhs, const SemanticVersion& rhs)
	{
		return (lhs.m_Major == rhs.m_Major) && (lhs.m_Minor == rhs.m_Minor) && (lhs.m_Patch == rhs.m_Patch);
	}

	bool operator!=(const SemanticVersion& lhs, const SemanticVersion& rhs)
	{
		return !(lhs == rhs);
	}
}