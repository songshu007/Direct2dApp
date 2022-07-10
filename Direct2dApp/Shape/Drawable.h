#pragma once
#include <d2d1.h>
#define PRINTF(text, handle) if(handle != NULL) {WriteConsoleW(handle, text, static_cast<DWORD>(wcslen(text)), NULL, 0);} else {};
#define ISOK(hr, okt, not, handle) if(SUCCEEDED(hr)) {PRINTF(okt, handle)} else {throw not;};
#define RELEASE(ptr) if(ptr != NULL) ptr->Release();

namespace app {
	/*ͼ�εĻ��࣬���е�ͼ���඼Ҫ�̳и���*/
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
		D2D1_COLOR_F m_FillColor;	// �����ɫ
		D2D1_COLOR_F m_FrameColor;	// �߿���ɫ
		D2D1_POINT_2F m_Position;	// λ��
		D2D1_POINT_2F m_CenterPos;	// ����λ��

		float m_FrameWidth;			// �߿���
		float m_Angle;				// �Ƕ�

	private:
		virtual void draw(ID2D1HwndRenderTarget* RenderTarget) = 0;
	};
}