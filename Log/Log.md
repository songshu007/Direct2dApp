## Log 日志

#### 2022-7-9-11-29（下午）

添加了`CircleShape`类，用来画圆，声明在`CircleShape.h`实现在`CircleShape.cpp`

`Direct2dApp.h`中添加了另一个构造函数：
```
Direct2dApp(HWND hwnd);
```
该构造函数不初始化 `标准输出句柄` 并修改了`Drawable.h`里的宏定义，以达到不向控制台输出的目的
另一个构造函数将初始化 `标准输出句柄` 以向控制台输出调试信息

调整了一下项目的结构，

该库所有文件都在`Direct2dApp/`目录下

所有的图形类，包括图形的`Drawable`基类都放到了`Direct2dApp/Shape/`目录下

`Direct2dApp`类则在`Direct2dApp/`目录下

#### 2022-7-10-10-30（上午）

把该库加到了`app`命名空间下
