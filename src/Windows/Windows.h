#pragma once
#include <sal.h>

namespace Windows
{
	#define HANDLE(name) using name = Handle; using name##_t = Handle; using H##name = Handle;
	using Handle = void *;
	HANDLE(Icon);
	HANDLE(Cursor);
	HANDLE(Brush);
	HANDLE(Menu);
	HANDLE(Module);
	HANDLE(Window);
	#undef HANDLE

	using Str = char *;
	using CStr = const char *;

	using WStr = wchar_t *;
	using CWStr = const wchar_t *;

	using uint = unsigned __int32;

	using Word = __int16;
	using DWord = __int32;

	using LParam = long *;
	using WParam = uint *;

	using Atom = unsigned __int16;

	using WinProc_t = void(__stdcall *)(_In_ Window win, _In_ uint msg, _In_ WParam wParam, _In_ LParam lParam);
	using WindowClass = struct WindowClass
	{
		uint Size;
		uint Style;
		WinProc_t WinProc;
		int ClassExtra;
		int WinExtra;
		Module Module;
		Icon Icon;
		Cursor Cursor;
		Brush Background;
		CWStr MenuName;
		CWStr ClassName;
		HIcon SmallIcon;
	};

	constexpr std::nullptr_t null = 0;

	extern Module Kernel32Lib;
	extern Module User32Lib;

	#include "Windows/WindowsImp.h"

	bool InitWindows();
}