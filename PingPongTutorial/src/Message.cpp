#include <easyx.h>
#include "../inc/Message.h"

static Coordinate mouse;

void PeekInputMessage()
{
    ExMessage msg;

    while (peekmessage(&msg, EX_MOUSE))
    {
        mouse.x = msg.x;
        mouse.y = msg.y;
    }
}

bool IsKeyDown(int key)
{
    return GetAsyncKeyState(key);
}

Coordinate GetMouseCoordinate()
{
    return mouse;
}
