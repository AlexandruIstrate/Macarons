#pragma once

#ifdef __WIN32
	#if __WIN64
		#define MR_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#endif

#ifdef MR_DEBUG
	#define MR_ENABLE_ASSERTS
#endif

#ifdef MR_ENABLE_ASSERTS
	#define MR_ASSERT(x, ...) { if(!(x)) { MR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MR_CORE_ASSERT(x, ...) { if(!(x)) { MR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MR_ASSERT(x, ...)
	#define MR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

