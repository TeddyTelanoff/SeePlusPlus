#include <Windows/Windows.h>

using namespace Windows;

Result MyWinProc(Window win, uint msg, WParam wParam, LParam lParam)
{
	switch (msg)
	{
	}
}

int main()
{
	if (!InitWindows())
		return 1;

	Module module = GetModule(null);

	WindowClass myClass = { sizeof(WindowClass) };
	myClass.WinProc = DefWinProc;
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
