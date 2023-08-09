#include <Windows.h>
#include <easyx.h>

int APIENTRY WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    initgraph(640, 480);    // 创建绘图窗口，大小为 640x480 像素
    circle(200, 200, 100);  // 画圆，圆心(200, 200)，半径 100

    // _getch();            // 窗口程序无法使用控制台输入输出
    Sleep(5000);            // 延时 5000 毫秒（声明在 Windows.h 中）

    closegraph();           // 关闭绘图窗口
    return 0;
}