#include <Windows/Windows.h>

constexpr std::nullptr_t null = 0;

int main()
{
	Windows::InitWindows();
	Windows::MessageBox(null, L"This is a test", L"Test!", 0);
}