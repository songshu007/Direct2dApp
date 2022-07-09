#include "./Direct2dApp/Direct2dApp.h"
#pragma comment(lib, "d2d1.lib")

Direct2dApp* D2dApp;
Rectshape* m_Rect;
HANDLE OutPutHandle;
float angle = 0.0f;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}break;
	case WM_CREATE:
	{
		/*初始化 矩形*/
		m_Rect = new Rectshape();
		m_Rect->setSize(D2D1::Point2F(150, 100));
		m_Rect->setPosition(D2D1::Point2F(100, 100));
		m_Rect->setCenterPos(D2D1::Point2F(75, 50));
		m_Rect->setFrameWidth(5.0f);
		m_Rect->setAngle(angle);
		m_Rect->setFrameColor(D2D1::ColorF(D2D1::ColorF::Blue, 1.0f));
		m_Rect->setFillColor(D2D1::ColorF(D2D1::ColorF::LightBlue, 0.5f));

		D2dApp = new Direct2dApp(hwnd);
		if (D2dApp->initD2d() == false)
		{
			PRINTF(L"D2D初始化失败！\n", OutPutHandle);
			PostQuitMessage(0);
		}
		else 
		{
			PRINTF(L"D2D初始化成功！\n", OutPutHandle);
		}
	}break;
	case WM_PAINT:
	{

	}break;
	case WM_SIZE:
	{
		D2dApp->ChangeSize(D2D1::SizeU(LOWORD(lParam), HIWORD(lParam)));
	}break;
	default:
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
#ifdef _DEBUG
	AllocConsole();
	OutPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif // _DEBUG

	HWND hwnd;
	WNDCLASSEX wic;
	wic.cbSize = sizeof(WNDCLASSEX);
	wic.hIcon = NULL;
	wic.hIconSm = NULL;
	wic.hCursor = LoadCursor(0, IDC_ARROW);	// 光标
	wic.hInstance = hInstance;
	wic.lpszClassName = __TEXT("Hello");//窗口类名
	wic.lpfnWndProc = WindowProc;//指明消息处理函数
	wic.lpszMenuName = NULL;//没有指明菜单项
	wic.cbClsExtra = 0;//在窗口类后没有扩展字节
	wic.cbWndExtra = 0;//结构或者是窗口实例
	wic.style = CS_HREDRAW | CS_VREDRAW;
	wic.hbrBackground = (HBRUSH)(COLOR_MENU);// 背景颜色

	if (!RegisterClassEx(&wic))
		return 0;

	hwnd = CreateWindowEx(0, __TEXT("Hello"), __TEXT("Test"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL/*附加消息*/);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	MSG msg = { 0 };
	while (1)
	{
		if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// 在这里绘制
			Sleep(1000 / 60);
			D2dApp->BeginDraw();

			D2dApp->Clear(D2D1::ColorF(D2D1::ColorF::AliceBlue, 1.0f));
			D2dApp->draw(m_Rect);

			D2dApp->EndDraw();

			m_Rect->setAngle(angle);
			angle += 0.5f;
		}
	}

	return 0;
}
