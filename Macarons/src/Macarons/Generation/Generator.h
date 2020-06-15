#pragma once

#include "mrpch.h"

#include "Macarons/Versioning/Repository.h"

namespace Macarons
{
	class Generator
	{
	public:
		Generator(const Repository& repo) : m_Repository{ repo } { }
		virtual ~Generator() {}

		inline const Repository& GetRepository() const { return m_Repository; }

		virtual std::string GetGeneratorName() const = 0;
		virtual std::string GetGeneratorDisplayName() const = 0;
		virtual std::unordered_set<std::string> GetSupportedFileExtensions() const = 0;

		virtual std::string Generate() = 0;

	protected:
		Repository m_Repository;
	};
}