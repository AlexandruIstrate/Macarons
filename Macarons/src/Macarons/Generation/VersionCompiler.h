#pragma once

namespace Macarons
{
	template <typename TVersionData>
	class VersionCompiler
	{
	public:
		virtual ~VersionCompiler() = default;

		virtual TVersionData GetVersion() const = 0;
	};
}