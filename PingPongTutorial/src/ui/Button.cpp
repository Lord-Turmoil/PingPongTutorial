// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../inc/ui/Button.h"
#include "../../inc/Message.h"

Button::Button(const Rect& range, const std::wstring& text)
    : _range(range), _text(text), _onClick(nullptr)
{
    for (int i = 0; i < BUTTON_STATE_NUM; i++)
    {
        _color[i] = RED;
    }
}

Button* Button::SetUpStyle(COLORREF color)
{
    _color[BUTTON_UP] = color;
    return this;
}

Button* Button::SetHoverStyle(COLORREF color)
{
    _color[BUTTON_HOVER] = color;
    return this;
}

Button* Button::SetDownStyle(COLORREF color)
{
    _color[BUTTON_DOWN] = color;
    return this;
}

Button* Button::SetText(const std::wstring& text)
{
    _text = text;
    return this;
}

Button* Button::SetOnClick(void (*onClick)(void))
{
    _onClick = onClick;
    return this;
}

void Button::Update()
{
    MouseMessage* msg = GetMouseMessage();
    if (_range.Contains(msg->pos))
    {
        if (msg->isDown)
        {
            _state = BUTTON_DOWN;
        }
        else if (msg->isUp)
        {
            if (_state == BUTTON_DOWN && _onClick)
            {
                _onClick();
            }
            _state = BUTTON_UP;
        }
        else
        {
            if (_state != BUTTON_DOWN)
            {
                _state = BUTTON_HOVER;
            }
        }
    }
    else
    {
        _state = BUTTON_UP;
    }
}

void Button::Draw()
{
    setlinestyle(PS_SOLID, 3);
    setlinecolor(_color[_state]);

    RECT rect = _range.ToEasyXRect();

    rectangle(rect.left, rect.top, rect.right, rect.bottom);
    drawtext(_text.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
