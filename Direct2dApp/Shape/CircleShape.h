#pragma once
#include "Drawable.h"

namespace app {
	class CircleShape : public Drawable
	{
	public:
		CircleShape();
		~CircleShape();
		void setRadius(float radiusX, float radiusY);
		float getRadiusX();
		float getRadiusY();

	private:
		virtual void draw(ID2D1HwndRenderTarget* RenderTarget);

		D2D1_POINT_2F m_Radius;			// ��С
		D2D1_POINT_2F m_CenterCircle;	// Բ��
		D2D1_ELLIPSE m_Eillipse;		// ��Բ
	};
}