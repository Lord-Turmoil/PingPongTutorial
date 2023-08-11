// Copyright (C) 2018 - 2023 Tony's Studio. All rights reserved.
// Licensed under the MIT License.

#include "../../inc/utils/Image.h"

void LoadImageResource(IMAGE* pDstImage, const wchar_t* filename)
{
    loadimage(pDstImage, filename);
}

void LoadImageResource(IMAGE* pDstImage, const wchar_t* filename, int srcX, int srcY, int srcWidth, int srcHeight)
{
    IMAGE tempImage;

    loadimage(&tempImage, filename);
    SetWorkingImage(&tempImage);
    getimage(pDstImage, srcX, srcY, srcWidth, srcHeight);
    SetWorkingImage();
}

void PutAlphaImage(int x, int y, IMAGE* pSrcImage)
{
    PutAlphaImage(nullptr, x, y, pSrcImage);
}

void PutAlphaImage(IMAGE* pDstImage, int x, int y, IMAGE* pSrcImage)
{
    DWORD* pDestBuffer = GetImageBuffer(pDstImage);
    const DWORD* pSrcBuffer = GetImageBuffer(pSrcImage);
    const int srcWidth = pSrcImage->getwidth();
    const int srcHeight = pSrcImage->getheight();
    const int destWidth = pDstImage ? pDstImage->getwidth() : getwidth();
    const int destHeight = pDstImage ? pDstImage->getheight() : getheight();

    int destX = x;
    int destY = y;

    if ((destX + srcWidth < 0) || (destY + srcHeight < 0) || (destX >= destWidth) || (destY >= destHeight))
    {
        return;
    }

    const int width = min(destX + srcWidth, destWidth) - max(destX, 0);
    const int height = min(destY + srcHeight, destHeight) - max(destY, 0);
    if (destX < 0)
    {
        pSrcBuffer -= destX;
        destX = 0;
    }
    if (destY < 0)
    {
        pSrcBuffer -= destY * srcWidth;
        destY = 0;
    }
    pDestBuffer += destWidth * destY + destX;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            const int alpha = (pSrcBuffer[j] & 0xff000000) >> 24;
            pDestBuffer[j] = ARGB(pSrcBuffer[j], pDestBuffer[j], alpha);
        }

        pDestBuffer += destWidth;
        pSrcBuffer += srcWidth;
    }
}
