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
