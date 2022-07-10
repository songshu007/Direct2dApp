# Direct2dApp
简单封装了 Direct2D 的图形库，用法接近SFML

# How Use?
只需在你的代码里`#include "Direct2dApp.h"`即可使用

然后使用`app`命名空间，库的所有功能都在`app`命名空间下
```
using namespace app;
```

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

`example`中只有一个`main.cpp`注意`main.cpp`的第一行代码：
```
#include "./Direct2dApp/Direct2dApp.h"
```
`Direct2dApp.h`在该存储库的`/Direct2dApp/`目录下，请让它们正确包含，该示例将不会再次更新，因为它只是一个示例，

如果想要实现画其它库中没有的图形，请让图形继承`Drawable`类，并实现`draw`方法，我后续也会持续更新

2022-7-9 该库新增了圆形

更多改动请在 Log 里查看：[点我直达](./Log/Log.md)
