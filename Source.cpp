#include<Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(
	HINSTANCE hInstance, // handle app
	HINSTANCE hPrevInstance, // handle prev app
	LPWSTR lpCmdStr,
	int nCmdShow)
{
	WNDCLASS wndClass;
	wndClass.style = 0;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	//wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(10, 40, 200));
	wndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndClass.hIcon = LoadIcon(NULL, IDI_QUESTION);
	wndClass.hInstance = hInstance;
	wndClass.lpszClassName = L"MainWndClass";
	wndClass.lpszMenuName = NULL;

	RegisterClass(&wndClass);
	HWND hwnd = CreateWindow(
		L"MainWndClass",
		L"Main Window Caption App",
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		1000,
		500,
		NULL,
		NULL,
		hInstance,
		0);

	if (!hwnd)
	{
		return FALSE;
	}

	ShowWindow(hwnd, SW_NORMAL);

	UpdateWindow(hwnd);

	MSG msg;

	while (GetMessage(&msg, hwnd, 0, 0) == TRUE)
	{
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		//...
		return 0;
	/*case WM_CLOSE:
		return 0;*/
	case WM_DESTROY:
		PostQuitMessage(0);
		return(0);
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}