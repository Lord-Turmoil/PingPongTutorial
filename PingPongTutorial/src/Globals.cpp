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
