#include "GameSystems.h"

bool GameSystems::quit = false;
SDL_Renderer* GameSystems::GameRenderer = nullptr;
SDL_Window* GameSystems::GameWindow = nullptr;
const uint8_t* GameSystems::keyboardState = nullptr;


void GameSystems::ReadInput()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    { 
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
    }

    keyboardState = SDL_GetKeyboardState(nullptr);
}

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