#include "CircleShape.h"

CircleShape::CircleShape()
	:Drawable(),
	m_Eillipse(D2D1::Ellipse(D2D1::Point2F(0.0f, 0.0f), 0.0f, 0.0f)),
	m_Radius(D2D1::Point2F(0.0f, 0.0f)),
	m_CenterCircle(D2D1::Point2F(0.0f, 0.0f))
{
}

CircleShape::~CircleShape()
{
}

void CircleShape::setRadius(float radiusX, float radiusY)
{
	this->m_Radius.x = radiusX;
	this->m_Radius.y = radiusY;
}

float CircleShape::getRadiusX()
{
	return this->m_Radius.x;
}

float CircleShape::getRadiusY()
{
	return this->m_Radius.y;
}

void CircleShape::draw(ID2D1HwndRenderTarget* RenderTarget)
{
	D2D1_MATRIX_3X2_F lastTransform = { 0 };
	RenderTarget->GetTransform(&lastTransform);
	this->m_Eillipse.point.x = this->m_Position.x - this->m_CenterPos.x;
	this->m_Eillipse.point.y = this->m_Position.y - this->m_CenterPos.y;
	this->m_Eillipse.radiusX = this->m_Radius.x;
	this->m_Eillipse.radiusY = this->m_Radius.y;

	RenderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(this->m_Angle, D2D1::Point2F(this->m_Position.x + this->m_CenterPos.x, this->m_Position.y + this->m_CenterPos.y)));

	ID2D1SolidColorBrush* Brush;
	RenderTarget->CreateSolidColorBrush(this->m_FillColor, &Brush);
	if (Brush != NULL)
		RenderTarget->FillEllipse(this->m_Eillipse, Brush);
	RenderTarget->CreateSolidColorBrush(this->m_FrameColor, &Brush);
	if (Brush != NULL)
		RenderTarget->DrawEllipse(this->m_Eillipse, Brush, this->m_FrameWidth);

	RenderTarget->SetTransform(lastTransform);
	RELEASE(Brush);
}
