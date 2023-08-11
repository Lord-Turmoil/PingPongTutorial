// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../inc/Sound.h"

static FMOD::System* system = nullptr;
static FMOD::Channel* sharedChannel = nullptr;

void InitFmodSystem()
{
    System_Create(&system);
    system->init(32l, FMOD_INIT_NORMAL, nullptr);
}

void UpdateFmodSystem()
{
    if (system)
    {
        system->update();
    }
}

void CloseFmodSystem()
{
    if (system)
    {
        system->close();
        system->release();
    }
}

void LoadFmodSound(FmodSound* pSound, const char* filename)
{
    system->createSound(filename, FMOD_DEFAULT, nullptr, &(pSound->snd));
}

void PlayFmodSound(FmodSound* pSound, bool share)
{
    if (share)
    {
        system->playSound(pSound->snd, nullptr, false, &sharedChannel);
    }
    else
    {
        bool isPlaying = false;
        if (pSound->chl)
        {
            pSound->chl->isPlaying(&isPlaying);
        }
        if (!isPlaying)
        {
            system->playSound(pSound->snd, nullptr, false, &(pSound->chl));
        }
    }
}
