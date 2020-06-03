#pragma once

#ifdef __WIN32
	#if __WIN64
		#define MR_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#endif

