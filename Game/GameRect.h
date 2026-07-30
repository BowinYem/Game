/*
A wrapper class for SDL_Rect and SDL_FRect - There are various SDL functions that either accept a Rect or FRect and it's 
annoying to having to distinguish between the two, so I created this wrapper class that encapsulates both types. 
*/

#pragma once
#include "SDL.h"
#include "SDL_rect.h"
#include "GameVector.h"

class GameRect
{
public:
    GameRect() = default;
    GameRect(const float x_, const float y_, const float w_, const float h_); 

    inline SDL_Rect  GetIRect() const { return { static_cast<int>(x), static_cast<int>(y), static_cast<int>(w), static_cast<int>(h) }; }
    inline SDL_FRect GetFRect() const { return { x, y, w, h}; }

    static bool HasIntersection (const GameRect& rectA, const GameRect& rectB);

    float x = 0.0f;
    float y = 0.0f;
    float w = 0.0f;
    float h = 0.0f;
};

