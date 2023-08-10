#include <Windows.h>
#include <easyx.h>
#include "../inc/Message.h"
#include "../inc/ui/Button.h"

void OnClickButton()
{
    circle(300, 300, 50);
}

int APIENTRY WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    initgraph(640, 480);
    BeginBatchDraw();

    Button button(Rect(50, 50, 200, 100), L"Click me");
    button.SetUpStyle(RED)->SetHoverStyle(YELLOW)->SetDownStyle(MAGENTA);
    button.SetOnClick(OnClickButton);

    MouseMessage* mouse;
    while (true)
    {
        cleardevice();

        // process input
        PeekMouseMessage();
        if (IsKeyDown(VK_Q))
        {
            break;
        }
        mouse = GetMouseMessage();

        // update game
        button.Update();

        // draw image
        button.Draw();
        circle((int)mouse->x, (int)mouse->y, 10);

        FlushBatchDraw();

        Sleep(15);
    }

    EndBatchDraw();
    closegraph();
    return 0;
}