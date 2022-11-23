
#define Win32_LEAN_AND_MEAN
#define VC_EXTRALEAN

#include <Windows.h>

int main();

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	INT       nShowCmd
)
{
	return main();
}