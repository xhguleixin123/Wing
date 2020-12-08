#pragma once

#ifdef W_PLATFORM_WINDOWS
	#ifdef W_BUILD_DLL
		#define WING_API __declspec(dllexport)
	#else 
		#define WING_API __declspec(dllimport)
	#endif // W_BUILD_DLL
#else
	#error Wing only supports Winows
#endif // W_PLATFORM_WINDOWS

#ifdef W_ENABLE_ASSERTS
#define W_CORE_ASSERT(x, ...) if(!(x)) { W_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }
#define W_ASSERT(x, ...) if(!(x)) { W_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }
#else
#define W_CORE_ASSERT(x, ...)
#define W_ASSERT(x, ...)
#endif // W_ENABLE_ASSERTS



#define BIT(x) (1<<x)