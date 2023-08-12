// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include <Windows.h>
#include <easyx.h>
#include "../inc/Message.h"
#include "../inc/Globals.h"
#include "../inc/ui/Application.h"
#include "../inc/ui/Interface.h"
#include "../inc/utils/Image.h"
#include "../inc/Sound.h"
#include "../inc/utils/Random.h"

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
        UpdateFmodSystem();

        // draw
        app->Draw();
        FlushBatchDraw();

        Sleep(15);
    }

    ClearUp();

    return 0;
}

void Init()
{
    SetRandomSeed();

    // init graph
    initgraph(1000, 560);
    setbkcolor(WHITE);
    settextcolor(BLACK);

    // init sound
    InitFmodSystem();

    // load image resource
    LoadImageResource(&batImage, L"res/Image.png", 0, 0, 20, 100);
    LoadImageResource(&ballImage, L"res/Image.png", 20, 0, 10, 10);

    // load sound resource
    LoadFmodSound(&bounceSound, "res/bounce.wav");
    LoadFmodSound(&scoreSound, "res/score.wav");

    // init application
    Application* app = GetApplication();
    app->RegisterInterface(new MainInterface())
       ->RegisterInterface(new GameInterface());

    BeginBatchDraw();
}

void ClearUp()
{
    CloseFmodSystem();

    EndBatchDraw();
    closegraph();
}
