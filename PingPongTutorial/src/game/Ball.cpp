// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../inc/game/Ball.h"
#include "../../inc/utils/Random.h"
#include "../../inc/Globals.h"
#include "../../inc/utils/Image.h"
#include <cmath>

Ball::Ball(double speed) : _speed(speed)
{
    _width = 10;
    _height = 10;
}

void Ball::Serve(double direction)
{
    const double PI = 3.1415926;
    double radian = Random(-60, 60) * PI / 180.0;
    direction = direction / std::abs(direction);

    _velocity.x = _speed * std::cos(radian) * direction;
    _velocity.y = _speed * std::sin(radian);
}

void Ball::Stop()
{
    _velocity.x = _velocity.y = 0.0;
}

void Ball::Move()
{
    _pos.x += _velocity.x;
    _pos.y += _velocity.y;
}

void Ball::Bounce(const Rect& rect)
{
    Rect box = GetBorder();
    Coordinate overlap = box.Intersect(rect);
    if (overlap.x < 0.0 || overlap.y < 0.0)
    {
        return;
    }

    Coordinate ballCenter = box.GetCenter();
    Coordinate rectCenter = rect.GetCenter();
    if (overlap.x > overlap.y)
    {
        // bounce on y
        if (ballCenter.y < rectCenter.y)
        {
            // hit on top
            overlap.y = -overlap.y;
        }
        _velocity.y = -_velocity.y;
        overlap.x = 0.0;
    }
    else
    {
        // bounce on x
        if (ballCenter.x < rectCenter.x)
        {
            overlap.x = -overlap.x;
        }
        _velocity.x = -_velocity.x;
        overlap.y = 0.0;
    }

    _pos = _pos + overlap;

    PlayFmodSound(&bounceSound, true);
}

void Ball::Attach(const Rect& rect, bool isLeft)
{
    Coordinate center = rect.GetCenter();
    _pos = center;
    _pos.y -= _height * 0.5;
    if (isLeft)
    {
        _pos.x -= rect.width * 0.5 + _width;
    }
    else
    {
        _pos.x += rect.width * 0.5;
    }
    Stop();
}

void Ball::Draw()
{
    PutAlphaImage(static_cast<int>(_pos.x), static_cast<int>(_pos.y), &ballImage);
}
