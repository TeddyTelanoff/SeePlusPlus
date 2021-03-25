#ifndef ImportFunc
#define ImportFunc(name, ret, ...) using name##_t = ret(__stdcall *)(##__VA_ARGS__); extern name##_t name
#endif

using namespace Windows;
ImportFunc(MessageBox, int, _In_opt_ Window, _In_ CWStr text, _In_ CWStr title, _In_ uint ty);
ImportFunc(ExitProcess, void, _In_ int exitCode);
ImportFunc(DefWinProc, void, _In_ Window, _In_ uint msg, _In_ WParam wParam, _In_ LParam lParam);
ImportFunc(GetModule, Module, _In_ CWStr name);
ImportFunc(RegisterClass, Atom, _In_ const WindowClass &name);
ImportFunc(RegisterClassPtr, Atom, _In_ const WindowClass *name);

ImportFunc(CreateWindow, Window, _In_ DWord exStyle, _In_ CWStr className, CWStr title, WindowStyle style,
	int x, int y, int width, int height, Window parent, Menu menu, Module module, void *params);
ImportFunc(SetWindowVisible, void, _In_ Window, _In_ bool show);

#undef ImportFunc