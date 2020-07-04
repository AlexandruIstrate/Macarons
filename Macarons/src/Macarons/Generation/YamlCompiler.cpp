#include "mrpch.h"
#include "YamlCompiler.h"

#include <fstream>

#include <yaml-cpp/yaml.h>
#include <yaml-cpp/eventhandler.h>

namespace Macarons
{
	using namespace YAML;

	YamlCompiler::YamlCompiler(const std::string& configPath) : m_YamlFilePath{ configPath }
	{
		Initialize();
	}

	YamlCompiler::~YamlCompiler()
	{
	}

	SemanticVersion YamlCompiler::GetVersion() const
	{
		const Node& versionNode = (*m_RootNode)["version"];

		const Node& major = versionNode["major"];
		const Node& minor = versionNode["minor"];
		const Node& patch = versionNode["patch"];

		return SemanticVersion(major.as<int>(), minor.as<int>(), patch.as<int>());
	}

	void YamlCompiler::Initialize()
	{
		m_RootNode = std::make_unique<Node>(YAML::LoadFile(m_YamlFilePath));
	}
}