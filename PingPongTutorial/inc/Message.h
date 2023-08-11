// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#pragma once

#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "Defines.h"

struct MouseMessage
{
    union
    {
        Coordinate pos;

        struct
        {
            double x;
            double y;
        };
    };

    bool isDown;
    bool isUp;

    MouseMessage()
    {
    }
};

void PeekMouseMessage();

bool IsKeyDown(int key);
MouseMessage* GetMouseMessage();

// extended virtual key scan code
#define VK_A	0x41
#define VK_B	0x42
#define VK_C	0x43
#define VK_D	0x44
#define VK_E	0x45
#define VK_F	0x46
#define VK_G	0x47
#define VK_H	0x48
#define VK_I	0x49
#define VK_J	0x4A
#define VK_K	0x4B
#define VK_L	0x4C
#define VK_M	0x4D
#define VK_N	0x4E
#define VK_O	0x4F
#define VK_P	0x50
#define VK_Q	0x51
#define VK_R	0x52
#define VK_S	0x53
#define VK_T	0x54
#define VK_U	0x55
#define VK_V	0x56
#define VK_W	0x57
#define VK_X	0x58
#define VK_Y	0x59
#define VK_Z	0x5A

#endif
