#pragma once
#include <d2d1.h>
#define PRINTF(text, handle) if(handle != NULL) {WriteConsoleW(handle, text, static_cast<DWORD>(wcslen(text)), NULL, 0);} else {};
#define ISOK(hr, okt, not, handle) if(SUCCEEDED(hr)) {PRINTF(okt, handle)} else {throw not;};
#define RELEASE(ptr) if(ptr != NULL) ptr->Release();

namespace app {
	/*图形的基类，所有的图形类都要继承该类*/
	class Drawable
	{
		friend class Direct2dApp;
	public:
		Drawable();
		~Drawable();

		void setFillColor(const D2D1_COLOR_F& color);
		void setFrameColor(const D2D1_COLOR_F& color);
		void setPosition(const D2D1_POINT_2F& pos);
		void setCenterPos(const D2D1_POINT_2F& center);
		void setFrameWidth(float width);
		void setAngle(float angle);

		const D2D1_COLOR_F& getFillColor();
		const D2D1_COLOR_F& getFrameColor();
		const D2D1_POINT_2F& getPosition();
		const D2D1_POINT_2F& getCenterPos();
		float getFrameWidth();
		float getAngle();

	protected:
		D2D1_COLOR_F m_FillColor;	// 填充颜色
		D2D1_COLOR_F m_FrameColor;	// 边框颜色
		D2D1_POINT_2F m_Position;	// 位置
		D2D1_POINT_2F m_CenterPos;	// 中心位置

		float m_FrameWidth;			// 边框宽度
		float m_Angle;				// 角度

	private:
		virtual void draw(ID2D1HwndRenderTarget* RenderTarget) = 0;
	};
}