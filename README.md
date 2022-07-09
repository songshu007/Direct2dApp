# Direct2dApp
简单封装了 Direct2D 的图形库，用法接近SFML

# How Use?
只需在你的代码里`#include "Direct2dApp.h"`即可使用

首先需要定义一个 App 对象
```
Direct2dApp* D2dApp;
D2dApp = new Direct2dApp(hwnd);
```

然后调用它的初始化函数
```
D2dApp->initD2d();
```
它返回一个值代表初始化失败与否

将消息循环改成下面这样
```
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
		}
	}
```
绘制的内容：
```
D2dApp->BeginDraw();

D2dApp->Clear(D2D1::ColorF(D2D1::ColorF::White));
D2dApp->draw(m_Rect);

D2dApp->EndDraw();
```
不建议在`WM_PAINT`消息里绘制，虽然微软说d2d只能在`WM_PAINT`消息里绘制，但是我实测不在该消息也可以

所以需要你自己实现Win32的窗口，代码示例请在`example`里查看

目前该库只有一个矩形类可以画，如果想要画其它图形，请让图形继承`Drawable`类，并实现`draw`方法，我后续也会持续更新
