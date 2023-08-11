// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#pragma once

#ifndef _GAME_OBJECT_H_
#define _GAME_OBJECT_H_

#include "../Defines.h"

class GameObject
{
protected:
    Coordinate _pos;
    double _width;
    double _height;

public:
    GameObject(double width = 0.0, double height = 0.0);
    virtual ~GameObject() = default;

    GameObject* SetCoordinate(const Coordinate& coord);
    GameObject* SetX(double x);
    GameObject* SetY(double y);
    GameObject* SetWidth(double width);
    GameObject* SetHeight(double height);

    Coordinate GetCoordinate() const;
    double GetX() const;
    double GetY() const;
    double GetWidth() const;
    double GetHeight() const;

    Rect GetBorder() const;
    virtual void Draw() = 0;
};

#endif
