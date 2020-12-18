#include<Windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(
	HINSTANCE hInstance, // handle app
	HINSTANCE hPrevInstance, // handle prev app
	LPWSTR lpCmdStr,
	int nCmdShow)
{
	WNDCLASS wndClassGreen;
	wndClassGreen.style = 0;
	wndClassGreen.lpfnWndProc = WndProc;
	wndClassGreen.cbClsExtra = 0;
	wndClassGreen.cbWndExtra = 0;
	wndClassGreen.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(125, 255, 0));
	wndClassGreen.hCursor = LoadCursor(NULL, IDC_HAND);
	wndClassGreen.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClassGreen.hInstance = hInstance;
	wndClassGreen.lpszClassName = L"MainWndClassGreen";
	wndClassGreen.lpszMenuName = NULL;

	WNDCLASS wndClassRed;
	wndClassRed.style = 0;
	wndClassRed.lpfnWndProc = WndProc;
	wndClassRed.cbClsExtra = 0;
	wndClassRed.cbWndExtra = 0;
	wndClassRed.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
	wndClassRed.hCursor = LoadCursor(NULL, IDC_HAND);
	wndClassRed.hIcon = LoadIcon(NULL, IDI_EXCLAMATION);
	wndClassRed.hInstance = hInstance;
	wndClassRed.lpszClassName = L"MainWndClassRed";
	wndClassRed.lpszMenuName = NULL;

	WNDCLASS wndClassPurple;
	wndClassPurple.style = 0;
	wndClassPurple.lpfnWndProc = WndProc;
	wndClassPurple.cbClsExtra = 0;
	wndClassPurple.cbWndExtra = 0;
	wndClassPurple.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(153, 0, 153));
	wndClassPurple.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndClassPurple.hIcon = LoadIcon(NULL, IDI_QUESTION);
	wndClassPurple.hInstance = hInstance;
	wndClassPurple.lpszClassName = L"MainWndClassPurple";
	wndClassPurple.lpszMenuName = NULL;

	RegisterClass(&wndClassGreen);
	RegisterClass(&wndClassRed);
	RegisterClass(&wndClassPurple);

	HWND hwndGreen = CreateWindow(L"MainWndClassGreen", L"Green",
		WS_OVERLAPPEDWINDOW, 10, 10, 410, 220, NULL, NULL, hInstance, 0);

	HWND hwndRed = CreateWindow(L"MainWndClassRed", L"Red",
		WS_OVERLAPPEDWINDOW, 50, 150, 400, 250, NULL, NULL, hInstance, 0);
			
	HWND hwndPurple = CreateWindow(L"MainWndClassPurple", L"Purple",
		WS_OVERLAPPEDWINDOW, 850, 150, 400, 250, NULL, NULL, hInstance, 0);

	if (!hwndGreen && !hwndRed && !hwndPurple)
	{
		return FALSE;
	}

	ShowWindow(hwndGreen, SW_MAXIMIZE);
	ShowWindow(hwndRed, SW_NORMAL);
	ShowWindow(hwndPurple, SW_NORMAL);

	UpdateWindow(hwndGreen);
	UpdateWindow(hwndRed);
	UpdateWindow(hwndPurple);

	MSG msg;

	while (GetMessage(&msg, hwndGreen, 0, 0) == TRUE
		|| GetMessage(&msg, hwndRed, 0, 0) == TRUE
		|| GetMessage(&msg, hwndPurple, 0, 0) == TRUE)
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