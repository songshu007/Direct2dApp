#include "Rectshape.h"

Rectshape::Rectshape()
	:Drawable(), 
	m_Rect(D2D1::RectF(0.0f, 0.0f, 0.0f, 0.0f)),
	m_Size(D2D1::Point2F(0.0f, 0.0f))
{
	
}

Rectshape::~Rectshape()
{
}

void Rectshape::setSize(const D2D1_POINT_2F& size)
{
	this->m_Size = size;
}

const D2D1_POINT_2F& Rectshape::getSize()
{
	return this->m_Size;
}

void Rectshape::draw(ID2D1HwndRenderTarget* RenderTarget)
{
	D2D1_MATRIX_3X2_F lastTransform = { 0 };
	RenderTarget->GetTransform(&lastTransform);
	RenderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(this->m_Angle, D2D1::Point2F(this->m_Rect.left + this->m_CenterPos.x, this->m_Rect.top + this->m_CenterPos.y)));

	this->m_Rect = {this->m_Position.x - this->m_CenterPos.x, this->m_Position.y - this->m_CenterPos.y,
			this->m_Position.x + this->m_Size.x - this->m_CenterPos.x, this->m_Position.y + this->m_Size.y - this->m_CenterPos.y };

	ID2D1SolidColorBrush* Brush;
	RenderTarget->CreateSolidColorBrush(this->m_FillColor, &Brush);
	if (Brush != NULL)
		RenderTarget->FillRectangle(this->m_Rect, Brush);
	RenderTarget->CreateSolidColorBrush(this->m_FrameColor, &Brush);
	if (Brush != NULL)
		RenderTarget->DrawRectangle(this->m_Rect, Brush, this->m_FrameWidth);

	RenderTarget->SetTransform(lastTransform);
	RELEASE(Brush);
}
