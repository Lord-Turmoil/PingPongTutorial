// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#pragma once

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <easyx.h>
#include <string>
#include "../Defines.h"

enum ButtonState
{
    BUTTON_UP = 0,
    BUTTON_HOVER,
    BUTTON_DOWN,
    BUTTON_STATE_NUM
};

class Button
{
private:
    Rect _range;

    ButtonState _state;
    COLORREF _color[BUTTON_STATE_NUM];

    std::wstring _text;

    void (*_onClick)(void);

public:
    Button(const Rect& range, const std::wstring& text);
    virtual ~Button() = default;

    Button* SetUpStyle(COLORREF color);
    Button* SetHoverStyle(COLORREF color);
    Button* SetDownStyle(COLORREF color);
    Button* SetText(const std::wstring& text);
    Button* SetOnClick(void (*onClick)(void));

    virtual void Update();
    virtual void Draw();
};

#endif
