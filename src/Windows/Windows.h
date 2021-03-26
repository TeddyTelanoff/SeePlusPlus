#pragma once
#include <sal.h>
//#include <Windows.h> // NO!

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
	HANDLE(DC);
	HANDLE(DeviceContext);
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
	using Result = uint *;

	using Color = DWord;

	using Bool = enum Bool
	{
		False = false,
		True = !False,
	};
	using Atom = unsigned __int16;

	enum WindowsMessage: unsigned __int16;
	using WinProc_t = void(__stdcall *)(_In_ Window, _In_ WindowsMessage msg, _In_ WParam wParam, _In_ LParam lParam);
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

	using Point = struct Point
	{ long X, Y; };

	using Rect = struct Rect
	{ long Left, Top, Right, Bottom; };

	using WinMessage = struct WinMessage
	{
		Window Win;
		uint Msg;
		WParam wParam;
		LParam lParam;
		DWord Time;
		Point Point;
		DWord Private;
	};

	using Paint = struct Paint
	{
		DC DC;
		Bool Erase;
		Rect Viewport;
		Bool Restore;
		Bool IncUpdate;
		Bool RGBReserved[32];
	};

	constexpr std::nullptr_t null = 0;

	extern Module Kernel32Lib;
	extern Module User32Lib;
	extern Module GDI32Lib;

	_Return_type_success_(true) bool InitWindows();
}

#include "Windows/WindowsConstants.h"
#include "Windows/WindowsMessages.h"
#include "Windows/WindowsStyles.h"
#include "Windows/WindowsColors.h"
#include "Windows/WindowsImp.h"