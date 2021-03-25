#ifndef ImportFunc
#define ImportFunc(name, ret, ...) using name##_t = ret(__stdcall *)(##__VA_ARGS__); extern name##_t name
#endif

namespace Windows
{
	ImportFunc(MessageBox, int, _In_opt_ Window, _In_ CWStr text, _In_ CWStr title, _In_ uint ty);
	ImportFunc(ExitProcess, void, _In_ int exitCode);
	ImportFunc(DefWinProc, Result, _In_ Window, _In_ uint msg, _In_ WParam wParam, _In_ LParam lParam);
	ImportFunc(GetModule, Module, _In_ CWStr name);
	ImportFunc(RegisterClass, Atom, _In_ const WindowClass &name);
	ImportFunc(RegisterClassPtr, Atom, _In_ const WindowClass *name);

	ImportFunc(CreateWindow, Window, _In_ DWord exStyle, _In_ CWStr className, _In_ CWStr title, _In_ WindowStyle style,
		_In_ int x, _In_ int y, _In_ int width, _In_ int height, _In_ Window parent, _In_ Menu menu, _In_ Module module, _In_ void *params);
	ImportFunc(SetWindowVisible, void, _In_ Window, _In_ bool show);

	ImportFunc(GetMessage, bool, _In_ WinMessage *msg, _In_ Window, _In_ uint msgFilterMin, _In_ uint msgFilterMax);
	ImportFunc(TranslateMessage, bool, _In_ const WinMessage &msg);
	ImportFunc(DispatchMessage, bool, _In_ const WinMessage &msg);
}

#undef ImportFunc