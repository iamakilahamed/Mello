#pragma once

#ifdef MELLO_PLATFORM_WINDOWS
	#ifdef MELLO_BUILD_DLL
		#define MELLO_API __declspec(dllexport)
	#else
		#define MELLO_API __declspec(dllimport)
	#endif
#else
	#error Mello only supports Windows
#endif