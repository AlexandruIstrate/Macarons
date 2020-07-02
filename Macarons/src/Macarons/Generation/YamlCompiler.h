#pragma once

#include "mrpch.h"

#include "VersionCompiler.h"
#include "Macarons/Core/SemanticVersion.h"
#include "Macarons/Versioning/Repository.h"

namespace YAML
{
	class Parser;
}

namespace Macarons
{
	class MacaronsYamlEventHandler;

	class YamlCompiler : public VersionCompiler<SemanticVersion>
	{
	public:
		YamlCompiler(const std::string& configPath);
		~YamlCompiler();

		virtual SemanticVersion GetVersion() const override;

		inline const std::string& GetYamlFilePath() const { return m_YamlFilePath; }
		inline void SetYamlFilePath(const std::string& path) { m_YamlFilePath = path; }

	private:
		void Initialize();

	private:
		std::string m_YamlFilePath;
		std::unique_ptr<YAML::Parser> m_Parser;
		std::unique_ptr<MacaronsYamlEventHandler> m_EventHandler;
	};
}