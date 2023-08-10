#pragma once

#ifndef _BAT_H_
#define _BAT_H_

#include "GameObject.h"

class Bat : public GameObject
{
protected:
    double _minY;
    double _maxY;

public:
    Bat(double minY, double maxY);

    void MoveUp(double deltaY);
    void MoveDown(double deltaY);

    void Draw() override;
};

#endif
