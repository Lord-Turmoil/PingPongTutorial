#pragma once

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <easyx.h>

void LoadImageResource(IMAGE* pDstImage, const wchar_t* filename);
void LoadImageResource(IMAGE* pDstImage, const wchar_t* filename, int srcX, int srcY, int srcWidth, int srcHeight);

#endif