#pragma once

#ifndef _BAT_CONTROLLER_H_
#define _BAT_CONTROLLER_H_

#include <string>

class Bat;

class BatController
{
private:
    std::wstring _name;

protected:
    Bat* _bat;
    double _speed;

public:
    BatController(const std::wstring& name, Bat* bat, double speed)
        : _name(name), _bat(bat), _speed(speed)
    {
    }

    virtual ~BatController() {}

    const std::wstring& Name() const { return _name; }
    virtual const wchar_t* GetTips() const { return L"None"; }

    virtual void Update() = 0;
};


class PlayerBatController final : public BatController
{
private:
    int _downKey;
    int _upKey;

public:
    PlayerBatController(const std::wstring& name, Bat* bat, int downKey, int upKey, double speed);

    void Update() override;
    const wchar_t* GetTips() const override;
};


class Ball;

class AiBatController final : public BatController
{
private:
    Ball* _ball;

public:
    AiBatController(const std::wstring& name, Bat* bat, Ball* ball, double speed);

    void Update() override;
    const wchar_t* GetTips() const override;
};

#endif
