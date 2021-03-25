#include "Windows/Windows.h"

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

	#define ImportFunc(name, ret, ...) using name##_t = ret (__stdcall *)(##__VA_ARGS__); name##_t name
	#include "Windows/WindowsImp.h"
	#undef ImportFunc

	#define LoadLib(name) name##Lib = NATIVE::LoadLibraryW(L#name); if (name##Lib == null) { NATIVE::MessageBoxW(null, L"Cannot load library '" L#name L"'", L"See++ Error", 0x10); return false; }
	#define LoadFunc(name, lib) name = (name##_t)NATIVE::GetProcAddress(lib, #name); if (name == null) { NATIVE::MessageBoxW(null, L"Cannot load function '" L#name L"' from library '" L#lib L"'", L"See++ Error", 0x10); return false; }
	#define LoadFuncAlias(name, fnName, lib) name = (name##_t)NATIVE::GetProcAddress(lib, fnName); if (name == null) { NATIVE::MessageBoxW(null, L"Cannot load function '" L#name L"' from library '" L#lib L"'", L"See++ Error", 0x10); return false; }
	bool InitWindows()
	{
		LoadLib(Kernel32);
		LoadFunc(ExitProccess, Kernel32Lib);
		
		LoadLib(User32);
		LoadFuncAlias(MessageBox, "MessageBoxW", User32Lib);

		return true;
	}
	#undef LoadLib
}
