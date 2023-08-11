// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../inc/game/Bat.h"
#include "../../inc/Globals.h"
#include "../../inc/utils/Image.h"

Bat::Bat(double minY, double maxY)
    : _minY(minY), _maxY(maxY)
{
    _width = 20;
    _height = 100;
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
    PutAlphaImage(static_cast<int>(_pos.x), static_cast<int>(_pos.y), &batImage);
}
