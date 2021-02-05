#include<Windows.h>
#include"resource.h"

#define FIRST_TIMER 2001

HINSTANCE hInst;
HWND hwnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcChild(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(
	HINSTANCE hInstance, // handle app
	HINSTANCE hPrevInstance, // handle prev app
	LPWSTR lpCmdStr,
	int nCmdShow)

{
	hInst = hInstance;

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

	WNDCLASS childWndClass;
	childWndClass.style = 0;
	childWndClass.lpfnWndProc = WndProcChild;
	childWndClass.cbClsExtra = 0;
	childWndClass.cbWndExtra = 0;
	childWndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(10, 40, 20));
	childWndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
	childWndClass.hIcon = LoadIcon(NULL, IDI_QUESTION);
	childWndClass.hInstance = hInstance;
	childWndClass.lpszClassName = L"ChildWndClass";
	childWndClass.lpszMenuName = NULL;

	RegisterClass(&wndClass);
	RegisterClass(&childWndClass);

	hwnd = CreateWindow(
		L"MainWndClass",
		L"Main Window Caption App",
		WS_OVERLAPPEDWINDOW,
		50,
		50,
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
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static WCHAR buf[100];

	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		RECT rect;
		GetClientRect(hwnd, &rect);

		DrawText(hdc, buf, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);
	}
	break;

	case WM_LBUTTONDOWN: {
		hwnd = CreateWindow(
			L"ChildWndClass",
			L"Child Window Caption App",
			WS_OVERLAPPEDWINDOW,
			100,
			100,
			500,
			200,
			NULL,
			NULL,
			hInst,
			0);

		ShowWindow(hwnd, SW_NORMAL);

	}  break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK WndProcChild(HWND hwndChild, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		UpdateWindow(hwndChild);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwndChild, message, wParam, lParam);
	}
}