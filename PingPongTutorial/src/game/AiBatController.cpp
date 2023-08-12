// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../inc/game/BatController.h"
#include "../../inc/game/Ball.h"
#include "../../inc/game/Bat.h"

AiBatController::AiBatController(const std::wstring& name, Bat* bat, double speed, Ball* ball)
    : BatController(name, bat, speed), _ball(ball)
{
}

void AiBatController::Update()
{
    if (!_bat || !_ball)
    {
        return;
    }

    Coordinate batCenter = _bat->GetBorder().GetCenter();
    Coordinate ballCenter = _ball->GetBorder().GetCenter();

    double delta = ballCenter.y - batCenter.y;
    if (delta > 5.0)
    {
        _bat->MoveDown(_speed);
    }
    else if (delta < -5.0)
    {
        _bat->MoveUp(_speed);
    }
}

const wchar_t* AiBatController::GetTips() const
{
    return L"Ai Player";
}
