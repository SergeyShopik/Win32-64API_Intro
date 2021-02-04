#include<Windows.h>
#include"resource.h"

#define FIRST_TIMER 2001

HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);


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
	childWndClass.lpfnWndProc = WndProc;
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

	HWND hwnd = CreateWindow(
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
	case WM_CREATE:
		SetTimer(hwnd, FIRST_TIMER, 1000, NULL);
		break;
		/*case WM_CLOSE:
			return 0;*/
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	//case WM_MOUSEMOVE:
	//{
	//	int x = LOWORD(lParam);
	//	int y = HIWORD(lParam);

	//	wsprintf(buf, L"x = %d; y = %d", x, y);

	//	InvalidateRect(hwnd, NULL, TRUE);

	//	/*HDC hdc = GetDC(hwnd);


	//	ReleaseDC(hwnd, hdc);*/
	//}
	//break;

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

	//case WM_RBUTTONDOWN:
	//	KillTimer(hwnd, FIRST_TIMER);
	//	break;

	//case WM_LBUTTONDOWN:
	//	SetTimer(hwnd, FIRST_TIMER, 1000, NULL);
	//	break;

	case WM_TIMER:
		SetClassLong(hwnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		InvalidateRect(hwnd, NULL, TRUE);
		break;

	case WM_KEYDOWN: {

		RECT rect;
		GetWindowRect(hwnd, &rect);

		switch (wParam)
		{
		case VK_UP:
			MoveWindow(hwnd, rect.left, rect.top - 10, 900, 700, FALSE);
			break;
		case VK_DOWN:
			MoveWindow(hwnd, rect.left, rect.top + 10, 900, 700, FALSE);
			break;
		case VK_LEFT:
			MoveWindow(hwnd, rect.left - 10, rect.top, 900, 700, FALSE);
			break;
		case VK_RIGHT:
			MoveWindow(hwnd, rect.left + 10, rect.top, 900, 700, FALSE);
			break;
		}
	} break;

	case WM_CHAR:
	{
		switch (wParam) {
		case 'c':
			MessageBox(hwnd, L"c - symbol", L"Char message", MB_OK);
		}
	} break;

	//case WM_LBUTTONDOWN: {
	//	DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, (DLGPROC)DialogProc);
	//} break;

	case WM_LBUTTONDOWN: {

		hwnd = CreateWindow(
			L"ChildWndClass",
			L"Child Window Caption App",
			WS_OVERLAPPEDWINDOW,
			100,
			100,
			100,
			100,
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

BOOL CALLBACK DialogProc(HWND dlg, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg) {
		case WM_INITDIALOG:
			return true;

		case WM_COMMAND:
		{
			switch (LOWORD(wparam)) {
			case IDCANCEL:
				EndDialog(dlg, TRUE);
				break;

			case IDOK: {
				/*int a = GetDlgItemInt(dlg, IDC_EDIT1, NULL, TRUE);
				int b = GetDlgItemInt(dlg, IDC_EDIT2, NULL, TRUE);
				int sum = a + b;
				SetDlgItemInt(dlg, IDC_EDIT3, sum, TRUE);*/

				/*STARTUPINFO si;
				PROCESS_INFORMATION pi;

				ZeroMemory(&si, sizeof(si));
				si.cb = sizeof(si);
				ZeroMemory(&pi, sizeof(pi));

				CreateProcess(L"C:\\Users\\HP\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Accessories", NULL, NULL, NULL, FALSE, NULL, 0, NULL, &si, &pi);

				Sleep(5000);

				TerminateProcess(pi.hProcess);*/

			} break;
			}
		}
		return true;
	}

	return false;
}
