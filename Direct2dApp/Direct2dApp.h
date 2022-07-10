#pragma once

#include "./Shape/Rectshape.h"
#include "./Shape/CircleShape.h"

namespace app {
	class Direct2dApp
	{
	public:
		Direct2dApp(HANDLE outputhandle, HWND hwnd);
		Direct2dApp(HWND hwnd);
		~Direct2dApp();

		bool initD2d();
		void BeginDraw();
		void Clear(const D2D1_COLOR_F& color);
		void draw(Drawable& shape);
		void draw(Drawable* shape);
		void EndDraw();
		void ChangeSize(const D2D1_SIZE_U& size);

	private:

		RECT rc;	//���ڿͻ�����С
		HWND m_hwnd;
		HANDLE m_OutPutHandle;
		ID2D1Factory* m_d2dFactory = nullptr;	// d2d����
		ID2D1HwndRenderTarget* m_d2dRenderTarget = nullptr;	// ��Ⱦ��Ŀ��

		void Release();

	};
}