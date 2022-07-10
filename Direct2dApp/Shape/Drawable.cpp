#include "Drawable.h"

using namespace app;

Drawable::Drawable()
	:m_FillColor(D2D1::ColorF(D2D1::ColorF::White, 0.0f)), 
	m_FrameColor(D2D1::ColorF(D2D1::ColorF::Black, 1.0f)),
	m_Position(D2D1::Point2F(0.0f, 0.0f)),
	m_CenterPos(D2D1::Point2F(0.0f, 0.0f)), 
	m_Angle(0.0f),
	m_FrameWidth(1.0f)
{
	
}

Drawable::~Drawable()
{
}

void Drawable::setFillColor(const D2D1_COLOR_F& color)
{
	this->m_FillColor = color;
}

void Drawable::setFrameColor(const D2D1_COLOR_F& color)
{
	this->m_FrameColor = color;
}

void Drawable::setPosition(const D2D1_POINT_2F& pos)
{
	this->m_Position = pos;
}

void Drawable::setCenterPos(const D2D1_POINT_2F& center)
{
	this->m_CenterPos = center;
}

void Drawable::setFrameWidth(float width)
{
	this->m_FrameWidth = width;
}

void Drawable::setAngle(float angle)
{
	this->m_Angle = angle;
}

const D2D1_COLOR_F& Drawable::getFillColor()
{
	return this->m_FillColor;
}

const D2D1_COLOR_F& Drawable::getFrameColor()
{
	return this->m_FrameColor;
}

const D2D1_POINT_2F& Drawable::getPosition()
{
	return this->m_Position;
}

const D2D1_POINT_2F& Drawable::getCenterPos()
{
	return this->m_CenterPos;
}

float Drawable::getFrameWidth()
{
	return this->m_FrameWidth;
}

float Drawable::getAngle()
{
	return this->m_Angle;
}
