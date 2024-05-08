#include "GameSystems.h"

bool GameSystems::GameSystems_Init()
{
    bool InitSuccess = false;

    if(GameWindow = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0))
        {InitSuccess = true;}

	if(GameRenderer = SDL_CreateRenderer(GameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
        {InitSuccess = true;}

    SDL_SetRenderDrawColor(GameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return InitSuccess;
}

bool GameSystems::GameSystems_Close()
{
    return 1;
}