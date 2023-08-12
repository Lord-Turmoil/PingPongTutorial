// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../inc/ui/Interface.h"
#include "../../inc/Message.h"
#include "../../inc/Globals.h"
#include "../../inc/ui/Application.h"
#include "../../inc/utils/Random.h"
#include "../../inc/game/Bat.h"
#include "../../inc/game/Ball.h"
#include "../../inc/game/BatController.h"
#include <cstdio>

GameInterface::GameInterface() : Interface(L"Game")
{
    _scores[0] = _scores[1] = 0;
    _turn = 0;
}

GameInterface::~GameInterface()
{
}

void GameInterface::OnEnter()
{
    // init bats
    _bats[0] = std::make_shared<Bat>(70, 410);
    _bats[0]->SetX(250)->SetY(280);

    _bats[1] = std::make_shared<Bat>(70, 410);
    _bats[1]->SetX(750)->SetY(280);

    // init ball
    _ball = std::make_shared<Ball>(10.0);

    // init bat controllers
    if (gameMode == SINGLE_PLAYER)
    {
        _controllers[0] = std::make_shared<PlayerBatController>(
            L"Player", _bats[0].get(), 5.0, VK_S, VK_W);
        _controllers[1] = std::make_shared<AiBatController>(
            L"AI", _bats[1].get(), 3.0, _ball.get());
    }
    else
    {
        _controllers[0] = std::make_shared<PlayerBatController>(
            L"Player 1", _bats[0].get(), 5.0, VK_S, VK_W);
        _controllers[1] = std::make_shared<PlayerBatController>(
            L"Player 2", _bats[1].get(), 5.0, VK_J, VK_I);
    }

    // init turn and score
    _turn = Random(0, 2);
    _scores[0] = _scores[1] = 0;

    // attach ball
    _ball->Attach(_bats[_turn]->GetBorder(), _turn);

    _started = false;
}

void GameInterface::OnExit()
{
}

void GameInterface::Update()
{
    if (IsKeyDown(VK_ESCAPE))
    {
        GetApplication()->ChangeInterface(L"Main");
    }

    _controllers[0]->Update();
    _controllers[1]->Update();

    bool newTurn = false;
    if (_started)
    {
        _ball->Move();
        _ball->Bounce(_bats[0]->GetBorder());
        _ball->Bounce(_bats[1]->GetBorder());
        _ball->Bounce(Rect(50, -30, 1000, 100));
        _ball->Bounce(Rect(50, 510, 1000, 100));
        if (_ball->GetX() < 150.0)
        {
            _scores[1] += 1;
            newTurn = true;
        }
        else if (_ball->GetX() > 850.0)
        {
            _scores[0] += 1;
            newTurn = true;
        }
    }
    else
    {
        _ball->Attach(_bats[_turn]->GetBorder(), _turn);
        if (IsKeyDown(VK_SPACE))
        {
            _ball->Serve(!_turn ? 1.0 : -1.0);
            _started = true;
        }
    }

    if (newTurn)
    {
        _turn = Random(0, 2);
        _started = false;
        PlayFmodSound(&scoreSound);
    }
}

void GameInterface::Draw()
{
    // table
    setlinestyle(PS_SOLID, 2);
    setlinecolor(BLACK);
    rectangle(150, 70, 850, 510);
    line(500, 70, 500, 510);

    // player name
    setlinecolor(LIGHTCYAN);
    line(0, 50, 100, 50);
    line(900, 50, 1000, 50);
    LOGFONT style;
    gettextstyle(&style);
    settextstyle(22, 0, L"Consolas");
    RECT rect0{ 0, 0, 100, 50 };
    RECT rect1{ 900, 0, 1000, 50 };
    drawtext(_controllers[0]->Name().c_str(), &rect0, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_controllers[1]->Name().c_str(), &rect1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    // score
    wchar_t scoreText[128];
    swprintf_s(scoreText, L"%d  VS  %d", _scores[0], _scores[1]);
    settextstyle(44, 0, L"Comic Sans MS");
    RECT scoreRect{ 0, 0, 1000, 50 };
    drawtext(scoreText, &scoreRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    // restore text style
    settextstyle(&style);

    _bats[0]->Draw();
    _bats[1]->Draw();
    _ball->Draw();
}
