#pragma once

namespace Macarons
{
	template <typename TVersionData>
	class VersionCompiler
	{
	public:
		virtual ~VersionCompiler() {}

		virtual TVersionData GetMajorVersion() const = 0;
		virtual TVersionData GetMinorVersion() const = 0;
		virtual TVersionData GetPatchVersion() const = 0;
	};
}