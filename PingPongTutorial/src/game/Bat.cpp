#include "../../inc/game/Bat.h"

Bat::Bat(double minY, double maxY)
    : _minY(minY), _maxY(maxY)
{
}

void Bat::MoveUp(double deltaY)
{
    if (deltaY > 0.0)
    {
        _pos.y -= deltaY;
        if (_pos.y < _minY)
        {
            _pos.y = _minY;
        }
    }
}

void Bat::MoveDown(double deltaY)
{
    if (deltaY > 0.0)
    {
        _pos.y += deltaY;
        if (_pos.y > _maxY)
        {
            _pos.y = _maxY;
        }
    }
}

void Bat::Draw()
{
    RECT rect = GetBorder().ToEasyXRect();

    setfillcolor(WHITE);
    fillrectangle(rect.left, rect.top, rect.right, rect.bottom);
}