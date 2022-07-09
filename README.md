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

之后只需要在你的`WM_POINT`里绘制就行了，示例如下
```
D2dApp->BeginDraw();

D2dApp->Clear(D2D1::ColorF(D2D1::ColorF::AliceBlue, 1.5f));
D2dApp->draw(m_Rect);

D2dApp->EndDraw();
```
不过我不建议在`WM_POINT`消息里绘制，最好将消息循环改成下面这样
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

