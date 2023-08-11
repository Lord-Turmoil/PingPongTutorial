// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../inc/utils/Random.h"

#include <cstdlib>
#include <ctime>

void SetRandomSeed()
{
    srand(static_cast<unsigned>(time(nullptr)));
}

// get random number in [0.0, 1.0]
double Random()
{
    return static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
}

double Random(double upper)
{
    return upper * Random();
}

double Random(double lower, double upper)
{
    return lower + (upper - lower) * Random();
}

// [0, upper)
int Random(int upper)
{
    return rand() % upper;
}

// [lower, upper)
int Random(int lower, int upper)
{
    if (upper <= lower)
    {
        return lower;
    }
    return lower + rand() % (upper - lower);
}
