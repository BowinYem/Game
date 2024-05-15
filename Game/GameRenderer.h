// C wrapper class - wraps SDL_Renderer

#pragma once
#include <SDL.h>

class GameTexture;

class GameRenderer
{

friend class GameTexture;

public:
    GameRenderer();
    ~GameRenderer();

    bool GameRendererClear();
    bool GameRendererCopy(const GameTexture& texture, const SDL_Rect& srcRect, const SDL_Rect& destRect);
    void GameRendererPresent();

private:
    SDL_Renderer* rendererSDLPtr;
};