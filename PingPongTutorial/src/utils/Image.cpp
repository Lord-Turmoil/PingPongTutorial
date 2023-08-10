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
