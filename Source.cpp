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
	wndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(10, 40, 200));
	wndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndClass.hIcon = LoadIcon(NULL, IDI_QUESTION);
	wndClass.hInstance = hInstance;
	wndClass.lpszClassName = L"MainWndClass";
	wndClass.lpszMenuName = NULL;

	WNDCLASS wndClassOrange;
	wndClassOrange.style = 0;
	wndClassOrange.lpfnWndProc = WndProc;
	wndClassOrange.cbClsExtra = 0;
	wndClassOrange.cbWndExtra = 0;
	wndClassOrange.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 145, 0));
	wndClassOrange.hCursor = LoadCursor(NULL, IDC_HAND);
	wndClassOrange.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClassOrange.hInstance = hInstance;
	wndClassOrange.lpszClassName = L"MainWndClassOrange";
	wndClassOrange.lpszMenuName = NULL;

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

	WNDCLASS wndClassPink;
	wndClassPink.style = 0;
	wndClassPink.lpfnWndProc = WndProc;
	wndClassPink.cbClsExtra = 0;
	wndClassPink.cbWndExtra = 0;
	wndClassPink.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 100, 100));
	wndClassPink.hCursor = LoadCursor(NULL, IDC_HAND);
	wndClassPink.hIcon = LoadIcon(NULL, IDI_EXCLAMATION);
	wndClassPink.hInstance = hInstance;
	wndClassPink.lpszClassName = L"MainWndClassPink";
	wndClassPink.lpszMenuName = NULL;

	WNDCLASS wndClassPaleBlue;
	wndClassPaleBlue.style = 0;
	wndClassPaleBlue.lpfnWndProc = WndProc;
	wndClassPaleBlue.cbClsExtra = 0;
	wndClassPaleBlue.cbWndExtra = 0;
	wndClassPaleBlue.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(145, 165, 255));
	wndClassPaleBlue.hCursor = LoadCursor(NULL, IDC_HAND);
	wndClassPaleBlue.hIcon = LoadIcon(NULL, IDI_EXCLAMATION);
	wndClassPaleBlue.hInstance = hInstance;
	wndClassPaleBlue.lpszClassName = L"MainWndClassPaleBlue";
	wndClassPaleBlue.lpszMenuName = NULL;

	WNDCLASS wndClassYellow;
	wndClassYellow.style = 0;
	wndClassYellow.lpfnWndProc = WndProc;
	wndClassYellow.cbClsExtra = 0;
	wndClassYellow.cbWndExtra = 0;
	wndClassYellow.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));
	wndClassYellow.hCursor = LoadCursor(NULL, IDC_HAND);
	wndClassYellow.hIcon = LoadIcon(NULL, IDI_EXCLAMATION);
	wndClassYellow.hInstance = hInstance;
	wndClassYellow.lpszClassName = L"MainWndClassYellow";
	wndClassYellow.lpszMenuName = NULL;

	WNDCLASS wndClassGrass;
	wndClassGrass.style = 0;
	wndClassGrass.lpfnWndProc = WndProc;
	wndClassGrass.cbClsExtra = 0;
	wndClassGrass.cbWndExtra = 0;
	wndClassGrass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 200, 0));
	wndClassGrass.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndClassGrass.hIcon = LoadIcon(NULL, IDI_QUESTION);
	wndClassGrass.hInstance = hInstance;
	wndClassGrass.lpszClassName = L"MainWndClassGrass";
	wndClassGrass.lpszMenuName = NULL;

	WNDCLASS wndClassMustard;
	wndClassMustard.style = 0;
	wndClassMustard.lpfnWndProc = WndProc;
	wndClassMustard.cbClsExtra = 0;
	wndClassMustard.cbWndExtra = 0;
	wndClassMustard.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(250, 200, 50));
	wndClassMustard.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndClassMustard.hIcon = LoadIcon(NULL, IDI_QUESTION);
	wndClassMustard.hInstance = hInstance;
	wndClassMustard.lpszClassName = L"MainWndClassMustard";
	wndClassMustard.lpszMenuName = NULL;

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

	RegisterClass(&wndClass);
	RegisterClass(&wndClassOrange);
	RegisterClass(&wndClassGreen);
	RegisterClass(&wndClassPink);
	RegisterClass(&wndClassPaleBlue);
	RegisterClass(&wndClassYellow);
	RegisterClass(&wndClassGrass);
	RegisterClass(&wndClassMustard);
	RegisterClass(&wndClassPurple);

	HWND hwnd = CreateWindow(
		L"MainWndClass",
		L"Main Window Caption App",
		WS_OVERLAPPEDWINDOW,
		10,
		10,
		410,
		220,
		NULL,
		NULL,
		hInstance,
		0);

	HWND hwndOrange = CreateWindow(L"MainWndClassOrange", L"Orange",
		WS_OVERLAPPEDWINDOW, 420, 10, 410, 220, NULL, NULL, hInstance, 0);

	HWND hwndGreen = CreateWindow(L"MainWndClassGreen", L"Green",
		WS_OVERLAPPEDWINDOW, 830, 10, 410, 220, NULL, NULL, hInstance, 0);

	HWND hwndPink = CreateWindow(L"MainWndClassPink", L"Pink",
		WS_OVERLAPPEDWINDOW, 10, 240, 410, 220, NULL, NULL, hInstance, 0);
			
	HWND hwndPaleBlue = CreateWindow(L"MainWndClassPaleBlue", L"PaleBlue",
		WS_OVERLAPPEDWINDOW, 420, 240, 410, 220, NULL, NULL, hInstance, 0);
	
	HWND hwndYellow = CreateWindow(L"MainWndClassYellow", L"Yellow",
		WS_OVERLAPPEDWINDOW, 830, 240, 410, 220, NULL, NULL, hInstance, 0);
	
	HWND hwndGrass = CreateWindow(L"MainWndClassGrass", L"Grass",
		WS_OVERLAPPEDWINDOW, 10, 470, 410, 220, NULL, NULL, hInstance, 0);
	
	HWND hwndMustard = CreateWindow(L"MainWndClassMustard", L"Mustard",
		WS_OVERLAPPEDWINDOW, 420, 470, 410, 220, NULL, NULL, hInstance, 0);

	HWND hwndPurple = CreateWindow(L"MainWndClassPurple", L"Purple",
		WS_OVERLAPPEDWINDOW, 830, 470, 410, 220, NULL, NULL, hInstance, 0);

	if (!hwnd && !hwndOrange && !hwndGreen && !hwndPink && !hwndPaleBlue
		&& !hwndYellow && !hwndGrass && !hwndMustard && !hwndPurple)
	{
		return FALSE;
	}

	ShowWindow(hwnd, SW_NORMAL);
	ShowWindow(hwndOrange, SW_NORMAL);
	ShowWindow(hwndGreen, SW_NORMAL);
	ShowWindow(hwndPink, SW_NORMAL);
	ShowWindow(hwndPaleBlue, SW_NORMAL);
	ShowWindow(hwndYellow, SW_NORMAL);
	ShowWindow(hwndGrass, SW_NORMAL);
	ShowWindow(hwndMustard, SW_NORMAL);
	ShowWindow(hwndPurple, SW_NORMAL);

	UpdateWindow(hwnd);
	UpdateWindow(hwndOrange);
	UpdateWindow(hwndGreen);
	UpdateWindow(hwndPink);
	UpdateWindow(hwndPaleBlue);
	UpdateWindow(hwndYellow);
	UpdateWindow(hwndGrass);
	UpdateWindow(hwndMustard);
	UpdateWindow(hwndPurple);

	MSG msg;

	while (GetMessage(&msg, hwnd, 0, 0) == TRUE
		|| GetMessage(&msg, hwndOrange, 0, 0) == TRUE
		|| GetMessage(&msg, hwndGreen, 0, 0) == TRUE
		|| GetMessage(&msg, hwndPink, 0, 0) == TRUE
		|| GetMessage(&msg, hwndPaleBlue, 0, 0) == TRUE
		|| GetMessage(&msg, hwndYellow, 0, 0) == TRUE
		|| GetMessage(&msg, hwndGrass, 0, 0) == TRUE
		|| GetMessage(&msg, hwndMustard, 0, 0) == TRUE
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