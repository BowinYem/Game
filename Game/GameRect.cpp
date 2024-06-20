#include "GameRect.h"

GameRect::GameRect(GameVector& pos, uint32_t width, uint32_t height)
{
    rectSDL.x = pos.x;
    rectSDL.y = pos.y;
    rectSDL.w = width;
    rectSDL.h = height;
}
