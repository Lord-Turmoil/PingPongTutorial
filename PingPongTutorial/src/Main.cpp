#include <Windows.h>
#include <easyx.h>
#include "../inc/Message.h"

int APIENTRY WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    initgraph(640, 480);
    BeginBatchDraw();

    MouseMessage* mouse;
    while (true)
    {
        // process input
        PeekMouseMessage();
        if (IsKeyDown(VK_Q))
        {
            break;
        }
        mouse = GetMouseMessage();

        // draw image
        cleardevice();
        circle((int)mouse->x, (int)mouse->y, 10);
        FlushBatchDraw();

        Sleep(15);
    }

    EndBatchDraw();
    closegraph();
    return 0;
}