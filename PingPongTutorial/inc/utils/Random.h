// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#pragma once

#ifndef _RANDOM_H_
#define _RANDOM_H_

void SetRandomSeed();

// get random number in [0.0, 1.0]
double Random();
double Random(double upper);
double Random(double lower, double upper);

int Random(int upper);
int Random(int lower, int upper);

#endif
