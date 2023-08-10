#include "../../inc/game/BatController.h"
#include "../../inc/game/Ball.h"
#include "../../inc/game/Bat.h"

AiBatController::AiBatController(const std::wstring& name, Bat* bat, Ball* ball, double speed)
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

    if (ballCenter.y < batCenter.y)
    {
        _bat->MoveUp(_speed);
    }
    else if (ballCenter.y > batCenter.y)
    {
        _bat->MoveDown(_speed);
    }
}

const wchar_t* AiBatController::GetTips() const
{
    return L"Ai Player";
}