#pragma once

#ifdef MR_PLATFORM_WINDOWS
	#ifdef MR_BUILD_DLL
		#define MACARONS_API __declspec(dllexport)
	#else
		#define MACARONS_API __declspec(dllimport)
	#endif
#else
	#error Platform not supported!
#endif
