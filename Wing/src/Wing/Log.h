#pragma once
#include<memory>
#include"Core.h"
#include"spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Wing
{
	class WING_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger> GetClientLogger() { return s_ClientLogger; }
		inline static std::shared_ptr<spdlog::logger> GetCoreLogger() { return s_CoreLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

#define W_CORE_TRACE(...)	::Wing::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define W_CORE_INFO(...)	::Wing::Log::GetCoreLogger()->info(__VA_ARGS__)
#define W_CORE_WARN(...)	::Wing::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define W_CORE_ERROR(...)	::Wing::Log::GetCoreLogger()->error(__VA_ARGS__)

#define W_TRACE(...)	::Wing::Log::GetClientLogger()->trace(__VA_ARGS__)
#define W_INFO(...)		::Wing::Log::GetClientLogger()->info(__VA_ARGS__)
#define W_WARN(...)		::Wing::Log::GetClientLogger()->warn(__VA_ARGS__)
#define W_ERROR(...)	::Wing::Log::GetClientLogger()->error(__VA_ARGS__)
