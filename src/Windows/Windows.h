#pragma once
#include <sal.h>

namespace Windows
{
	using Handle = void *;
	using Module = Handle;
	using Window = Handle;

	using Str = char *;
	using CStr = const char *;

	using WStr = wchar_t *;
	using CWStr = const wchar_t *;

	using uint = unsigned int;

	constexpr std::nullptr_t null = 0;

	extern Module Kernel32Lib;
	extern Module User32Lib;

	#define ImportFunc(name, ret, ...) using name##_t = ret (__stdcall *)(##__VA_ARGS__); extern name##_t name
	#include "Windows/WindowsImp.h"
	#undef ImportFunc

	bool InitWindows();
}