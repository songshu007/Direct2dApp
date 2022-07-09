#include "Direct2dApp.h"

Direct2dApp::Direct2dApp(HANDLE outputhandle, HWND hwnd)
	:m_OutPutHandle(outputhandle), m_hwnd(hwnd)
{
	GetClientRect(m_hwnd, &rc);
}

Direct2dApp::Direct2dApp(HWND hwnd)
	:m_OutPutHandle(NULL), m_hwnd(hwnd)
{
	GetClientRect(m_hwnd, &rc);
}

Direct2dApp::~Direct2dApp()
{
	this->Release();
}

bool Direct2dApp::initD2d()
{
	HRESULT hr = S_OK;
	try {
		// 创建工厂
		hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, __uuidof(ID2D1Factory), (void**)&m_d2dFactory);
		ISOK(hr, L"工厂创建成功！\n", L"工厂创建失败！\n", this->m_OutPutHandle);

		// 渲染器目标
		hr = m_d2dFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(m_hwnd, D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top)), &m_d2dRenderTarget);
		ISOK(hr, L"渲染器目标创建成功！\n", L"渲染器目标创建失败！\n", this->m_OutPutHandle);

		// 设置抗锯齿
		m_d2dRenderTarget->SetAntialiasMode(D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);

	}
	catch (const wchar_t* e)
	{
		PRINTF(e, this->m_OutPutHandle);
		return false;
	}
	return true;
}

void Direct2dApp::BeginDraw()
{
	this->m_d2dRenderTarget->BeginDraw();
}

void Direct2dApp::Clear(const D2D1_COLOR_F& color)
{
	this->m_d2dRenderTarget->Clear(color);
}

void Direct2dApp::draw(Drawable& shape)
{
	shape.draw(this->m_d2dRenderTarget);
}

void Direct2dApp::draw(Drawable* shape)
{
	shape->draw(this->m_d2dRenderTarget);
}

void Direct2dApp::EndDraw()
{
	this->m_d2dRenderTarget->EndDraw();
}

void Direct2dApp::ChangeSize(const D2D1_SIZE_U& size)
{
	this->m_d2dRenderTarget->Resize(size);
}

void Direct2dApp::Release()
{
	RELEASE(m_d2dFactory);
	RELEASE(m_d2dRenderTarget);
}
