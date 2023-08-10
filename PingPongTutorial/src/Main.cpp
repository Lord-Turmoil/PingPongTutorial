#include <Windows.h>
#include <easyx.h>
#include "../inc/Message.h"
#include "../inc/Globals.h"
#include "../inc/ui/Application.h"
#include "../inc/utils/Image.h"

void Init();
void ClearUp();

int APIENTRY WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    // initialization
    Init();

    Application* app = GetApplication();
    while (isRunning)
    {
        cleardevice();

        // process input
        PeekMouseMessage();

        // update game
        app->Update();

        // draw
        app->Draw();
        FlushBatchDraw();

        Sleep(15);
    }
    
    return 0;
}

void Init()
{
    initgraph(1000, 560);
    setbkcolor(WHITE);
    settextcolor(BLACK);

    // load image resource
    LoadImageResource(&batImage, L"res/Image.png", 0, 0, 20, 100);
    LoadImageResource(&ballImage, L"res/Image.png", 20, 0, 10, 10);

    // init application
    Application* app = GetApplication();
    app->RegisterInterface(new MainInterface())
        ->RegisterInterface(new GameInterface());

    BeginBatchDraw();
}

void ClearUp()
{
    EndBatchDraw();
    closegraph();
}
