#include "GameSystems.h"
#include "GameRenderer.h"

bool GameSystems::quit = false;
std::shared_ptr<GameRenderer> GameSystems::renderer{nullptr};
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
    bool InitSuccess = true;

    if(GameWindow = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0))
        {InitSuccess = false;}


    // call make_unique for GameRenderer here - make sure to initialize window first
    renderer = std::make_shared<GameRenderer>();
    if(!renderer)
        { InitSuccess = false; }    

    return InitSuccess;
}

bool GameSystems::GameSystems_Close()
{
    return 1;
}