// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../inc/Globals.h"

#include "../inc/ui/Application.h"

static Application application;

Application* GetApplication()
{
    return &application;
}

bool isRunning = true;

int gameMode = 0;

// image resource
IMAGE batImage;
IMAGE ballImage;

// sound resource
FmodSound bounceSound;
FmodSound scoreSound;
