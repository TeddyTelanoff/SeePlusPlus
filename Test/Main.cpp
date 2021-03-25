#include <Windows/Windows.h>

using namespace Windows;

int main()
{
	InitWindows();

	Module module = GetModule(null);

	WindowClass myClass = { sizeof(WindowClass) };
	myClass.WinProc = DefWinProc;
	myClass.Module = module;
	myClass.ClassName = L"MyClass";
	RegisterClass(myClass);

	Window win = CreateWindow(0, L"MyClass", L"Title", 0xCF0000, 0x80000000, 0x80000000, 0x80000000, 0x80000000, null, null, module, null);
	SetWindowVisible(win, true);

	MessageBox(null, L"This is a test", L"Test!", 0);
	ExitProcess(69);
}
