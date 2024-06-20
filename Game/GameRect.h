// A wrapper class for SDL_Rect

#pragma once
#include "SDL.h"
#include "GameVector.h"

class GameRect
{
public:
    GameRect(GameVector& pos, uint32_t width, uint32_t height);    

private: 
    SDL_Rect rectSDL;
};