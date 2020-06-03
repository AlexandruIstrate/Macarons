#pragma once

#include "Macarons/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Macarons
{
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define MR_CORE_TRACE(...)		::Macarons::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MR_CORE_INFO(...)		::Macarons::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MR_CORE_WARN(...)		::Macarons::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MR_CORE_ERROR(...)		::Macarons::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MR_CORE_CRITICAL(...)	::Macarons::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MR_TRACE(...)			::Macarons::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MR_INFO(...)			::Macarons::Log::GetClientLogger()->info(__VA_ARGS__)
#define MR_WARN(...)			::Macarons::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MR_ERROR(...)			::Macarons::Log::GetClientLogger()->error(__VA_ARGS__)
#define MR_CRITICAL(...)		::Macarons::Log::GetClientLogger()->critical(__VA_ARGS__)