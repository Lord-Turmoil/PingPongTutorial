#pragma once

#ifndef _RANDOM_H_
#define _RANDOM_H_

void SetRandomSeed();

// get random number in [0.0, 1.0]
double Random();
double Random(double upper);
double Random(double lower, double upper);

#endif
