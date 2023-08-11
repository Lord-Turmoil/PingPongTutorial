// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#pragma once

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <string>
#include <memory>
#include "Button.h"

class Interface
{
private:
    std::wstring _name;

public:
    Interface(const std::wstring& name) : _name(name)
    {
    }

    virtual ~Interface()
    {
    }

    const std::wstring& Name() const { return _name; }

    virtual void OnEnter()
    {
    }

    virtual void OnExit()
    {
    }

    virtual void Update()
    {
    }

    virtual void Draw()
    {
    }
};


class MainInterface : public Interface
{
private:
    Button* _pOnePlayerButton;
    Button* _pTwoPlayerButton;
    Button* _pExitButton;

public:
    MainInterface();
    ~MainInterface() override;

    void Update() override;
    void Draw() override;

private:
    static void _OnClickOnePlayerButton();
    static void _OnClickTwoPlayerButton();
    static void _OnClickExitButton();
};


class Bat;
class BatController;
class Ball;

class GameInterface : public Interface
{
private:
    std::shared_ptr<Bat> _bats[2];
    std::shared_ptr<BatController> _controllers[2];
    std::shared_ptr<Ball> _ball;

    int _scores[2];

    int _turn;
    bool _started;

public:
    GameInterface();
    ~GameInterface() override;

    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    void Draw() override;
};

#endif
