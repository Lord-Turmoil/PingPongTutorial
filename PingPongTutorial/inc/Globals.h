// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#pragma once

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <easyx.h>
#include "Sound.h"

class Application;
Application* GetApplication();

extern bool isRunning;

const int SINGLE_PLAYER = 0;
const int DOUBLE_PLAYER = 1;

extern int gameMode;

// image resource
extern IMAGE batImage;
extern IMAGE ballImage;

// sound resource
extern FmodSound bounceSound;
extern FmodSound scoreSound;

#endif
