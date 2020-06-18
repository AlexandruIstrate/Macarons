#include "mrpch.h"
#include "GitFlowCompiler.h"

namespace Macarons
{
	GitFlowCompiler::GitFlowCompiler(const Repository& repository) : m_Repository{ repository }
	{
	}

	int GitFlowCompiler::GetMajorVersion() const
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	int GitFlowCompiler::GetMinorVersion() const
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	int GitFlowCompiler::GetPatchVersion() const
	{
		throw std::logic_error("The method or operation is not implemented.");
	}
}