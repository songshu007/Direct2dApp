#pragma once
#include "Drawable.h"

/*矩形类*/
class Rectshape : public Drawable
{
public:
	Rectshape();
	~Rectshape();
	void setSize(const D2D1_POINT_2F& size);
	const D2D1_POINT_2F& getSize();

private:
	virtual void draw(ID2D1HwndRenderTarget* RenderTarget);

	D2D1_RECT_F m_Rect;			// 矩形
	D2D1_POINT_2F m_Size;		// 大小
};

