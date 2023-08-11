// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#pragma once

#ifndef _BALL_H_
#define _BALL_H_

#include "../Defines.h"
#include "GameObject.h"

class Ball : public GameObject
{
protected:
    double _speed;
    Vector _velocity;

public:
    Ball(double speed);

    // direction should be 1 or -1
    void Serve(double direction);
    void Stop();
    void Move();

    void Bounce(const Rect& rect);
    void Attach(const Rect& rect, bool isLeft);

    void Draw() override;
};

#endif
