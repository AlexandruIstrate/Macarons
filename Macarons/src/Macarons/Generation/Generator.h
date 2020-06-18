#pragma once

#include "mrpch.h"

namespace Macarons
{
	class Generator
	{
	public:
		virtual ~Generator() {}

		virtual std::string GetName() const = 0;
		virtual std::string GetDisplayName() const = 0;
		virtual std::unordered_set<std::string> GetSupportedFileExtensions() const = 0;

		virtual std::string Generate() = 0;
	};
}