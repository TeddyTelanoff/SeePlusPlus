#include <Windows/Windows.h>

using namespace Windows;

Result __stdcall MyWinProc(Window win, WindowsMessage msg, WParam wParam, LParam lParam)
{
	switch (msg)
	{
	case WM_PAINT:
	{
		Paint paint;
		DC dc = BeginPaint(win, &paint);
		Brush br = CreateSolidBrush(0x404040);
		FillRect(dc, paint.Viewport, br);
		DeleteBrush(br);
		EndPaint(win, paint);
		return 0;
	}
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

	Window win = CreateWindow(0, L"MyClass", L"Title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, null, null, module, null);
	if (win == null)
		ExitProcess(1);
	SetWindowVisible(win, True);

	WinMessage msg;
	while (GetMessage(&msg, null, 0, 0))
	{
		TranslateMessage(msg);
		DispatchMessage(msg);
	}
}
