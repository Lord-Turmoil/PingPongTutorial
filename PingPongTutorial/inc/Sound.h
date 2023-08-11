#pragma once

#ifndef _SOUND_H_
#define _SOUND_H_

#include "3rd-party/fmod.hpp"

struct FmodSound
{
    FMOD::Sound* snd;
    FMOD::Channel* chl;

    FmodSound() : snd(nullptr), chl(nullptr)
    {
    }

    ~FmodSound()
    {
        if (snd)
        {
            snd->release();
        }
    }
};

void InitFmodSystem();
void UpdateFmodSystem();
void CloseFmodSystem();

void LoadFmodSound(FmodSound* pSound, const char* filename);
void PlayFmodSound(FmodSound* pSound, bool share = false);

#pragma comment(lib, "lib/fmod_vc.lib")

#endif
