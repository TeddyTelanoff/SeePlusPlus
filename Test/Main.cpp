#include <Windows/Windows.h>

using namespace Windows;

Result MyWinProc(Window win, WindowNotification msg, WParam wParam, LParam lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWinProc(win, msg, wParam, lParam);
}

int main()
{
	if (!InitWindows())
		return 1;

	Module module = GetModule(null);

	WindowClass myClass = { sizeof(WindowClass) };
	myClass.WinProc = (WinProc_t)MyWinProc;
	myClass.Module = module;
	myClass.ClassName = L"MyClass";
	RegisterClass(myClass);

	Window win = CreateWindow(0, L"MyClass", L"Title", WS_OVERLAPPEDWINDOW, 0x80000000, 0x80000000, 0x80000000, 0x80000000, null, null, module, null);
	if (win == null)
		ExitProcess(1);
	SetWindowVisible(win, true);

	WinMessage msg;
	while (GetMessage(&msg, null, 0, 0))
	{
		TranslateMessage(msg);
		DispatchMessage(msg);
	}

	MessageBox(null, L"This is a test", L"Test!", 0);
	ExitProcess(0);
}
