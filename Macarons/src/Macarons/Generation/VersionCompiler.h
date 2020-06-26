#pragma once

namespace Macarons
{
	template <typename TVersionData>
	class VersionCompiler
	{
	public:
		virtual ~VersionCompiler() {}

		virtual TVersionData GetVersion() const = 0;
	};
}