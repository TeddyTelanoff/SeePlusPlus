#include "Windows/Windows.h"

#define ImportFunc(name, ret, ...) name##_t name
#include "Windows/WindowsImp.h"

namespace Windows
{
	namespace NATIVE
	{
		extern "C" void __stdcall MessageBoxW(_In_opt_ Window win, _In_ CWStr text, _In_ CWStr title, _In_ uint ty);
		extern "C" Module __stdcall LoadLibraryW(_In_ CWStr name);
		extern "C" void *__stdcall GetProcAddress(_In_ Module lib, _In_ CStr name);
	}

	Module Kernel32Lib;
	Module User32Lib;
	Module GDI32Lib;

	#define LoadLib(name) name##Lib = NATIVE::LoadLibraryW(L#name); if (name##Lib == null) { NATIVE::MessageBoxW(null, L"Cannot load library '" L#name L"'", L"See++ Error", 0x10); return false; }
	#define LoadFunc(name, lib) name = (name##_t)NATIVE::GetProcAddress(lib, #name); if (name == null) { NATIVE::MessageBoxW(null, L"Cannot load function '" L#name L"' from library '" L#lib L"'", L"See++ Error", 0x10); return false; }
	#define LoadFuncAlias(name, fnName, lib) name = (name##_t)NATIVE::GetProcAddress(lib, fnName); if (name == null) { NATIVE::MessageBoxW(null, L"Cannot load function '" L#name L"' from library '" L#lib L"'", L"See++ Error", 0x10); return false; }
	_Return_type_success_(true) bool InitWindows()
	{
		LoadLib(Kernel32);
		LoadFunc(ExitProcess, Kernel32Lib);
		LoadFuncAlias(GetModule, "GetModuleHandleW", Kernel32Lib);
		
		LoadLib(User32);
		LoadFuncAlias(MessageBox, "MessageBoxW", User32Lib);
		LoadFuncAlias(DefWinProc, "DefWindowProcW", User32Lib);
		LoadFuncAlias(RegisterClass, "RegisterClassExW", User32Lib);
		LoadFuncAlias(RegisterClassPtr, "RegisterClassExW", User32Lib);

		LoadFuncAlias(CreateWindow, "CreateWindowExW", User32Lib);
		LoadFuncAlias(SetWindowVisible, "ShowWindow", User32Lib);
		LoadFuncAlias(GetMessage, "GetMessageW", User32Lib);
		LoadFunc(TranslateMessage, User32Lib);
		LoadFuncAlias(DispatchMessage, "DispatchMessageW", User32Lib);

		LoadFunc(PostQuitMessage, User32Lib);

		LoadFunc(BeginPaint, User32Lib);
		LoadFunc(EndPaint, User32Lib);
		LoadFunc(FillRect, User32Lib);

		LoadLib(GDI32);

		return true;
	}
	#undef LoadLib
}
