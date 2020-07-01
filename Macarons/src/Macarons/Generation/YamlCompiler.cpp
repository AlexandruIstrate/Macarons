#include "mrpch.h"
#include "YamlCompiler.h"

#include <fstream>

#include <yaml-cpp/yaml.h>
#include <yaml-cpp/eventhandler.h>

namespace Macarons
{
	using namespace YAML;

	class MacaronsYamlEventHandler : public EventHandler
	{
	public:
		void OnDocumentStart(const Mark& mark) override
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		void OnDocumentEnd() override
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		void OnNull(const Mark& mark, anchor_t anchor) override
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		void OnAlias(const Mark& mark, anchor_t anchor) override
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		void OnScalar(const Mark& mark, const std::string& tag, anchor_t anchor, const std::string& value) override
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		void OnSequenceStart(const Mark& mark, const std::string& tag, anchor_t anchor, EmitterStyle::value style) override
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		void OnSequenceEnd() override
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		void OnMapStart(const Mark& mark, const std::string& tag, anchor_t anchor, EmitterStyle::value style) override
		{
			throw std::logic_error("The method or operation is not implemented.");
		}

		void OnMapEnd() override
		{
			throw std::logic_error("The method or operation is not implemented.");
		}
	};

	YamlCompiler::YamlCompiler(const std::string& configPath) : m_YamlFilePath{ configPath }
	{
		Initialize();
	}

	YamlCompiler::~YamlCompiler()
	{
	}

	SemanticVersion YamlCompiler::GetVersion() const
	{
		// Reload the file path
		m_Parser->Load(std::ifstream(m_YamlFilePath));

		m_Parser->HandleNextDocument(*m_EventHandler);

		return SemanticVersion(1, 0, 0);
	}

	void YamlCompiler::Initialize()
	{
		m_Parser = std::make_unique<Parser>(std::ifstream(m_YamlFilePath));
		m_EventHandler = std::make_unique<MacaronsYamlEventHandler>();
	}
}