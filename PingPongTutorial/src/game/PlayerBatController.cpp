#include "../../inc/game/BatController.h"
#include "../../inc/Message.h"
#include "../../inc/game/Bat.h"

PlayerBatController::PlayerBatController(const std::wstring& name, Bat* bat, int downKey, int upKey, double speed)
    : BatController(name, bat, speed), _downKey(downKey), _upKey(upKey)
{
}

void PlayerBatController::Update()
{
    if (!_bat)
    {
        return;
    }

    if (IsKeyDown(_downKey))
    {
        _bat->MoveDown(_speed);
    }
    if (IsKeyDown(_upKey))
    {
        _bat->MoveUp(_speed);
    }
}

const wchar_t* PlayerBatController::GetTips() const
{
    return L"Human Player";
}
