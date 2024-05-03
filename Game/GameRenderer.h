#pragma once
#include <SDL.h>

class GameRenderer
{
public:
    static GameRenderer* GetRenderer();
    inline int GameRendererClear();
    inline void GameRendererPresent();

private:

    SDL_Renderer* Renderer;
    SDL_Window* GameWindow;  

    GameRenderer();
    ~GameRenderer();    
};