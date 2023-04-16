#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Mello {

	class MELLO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define MELLO_CORE_TRACE(...)		::Mello::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MELLO_CORE_INFO(...)        ::Mello::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MELLO_CORE_WARN(...)        ::Mello::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MELLO_CORE_ERROR(...)       ::Mello::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MELLO_CORE_FATAL(...)       ::Mello::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MELLO_TRACE(...)		    ::Mello::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MELLO_INFO(...)             ::Mello::Log::GetClientLogger()->info(__VA_ARGS__)
#define MELLO_WARN(...)             ::Mello::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MELLO_ERROR(...)            ::Mello::Log::GetClientLogger()->error(__VA_ARGS__)
#define MELLO_FATAL(...)            ::Mello::Log::GetClientLogger()->fatal(__VA_ARGS__)
