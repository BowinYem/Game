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
    bool GameRendererCopy(const GameTexture& texture, const SDL_Rect& srcRect, const SDL_Rect& destRect, const double rotation);
    void GameRendererPresent();
    bool GameRendererDrawLine(const SDL_FPoint& originPoint, const SDL_FPoint& destPoint);

private:
    SDL_Renderer* rendererSDLPtr;
};