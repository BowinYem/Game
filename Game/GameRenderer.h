// C wrapper class - wraps SDL_Renderer

#pragma once
#include <SDL.h>
#include "GameVector.h"
#include "GameTexture.h"
#include "GameRect.h"

// Forward Declarations
class GameTexture;

class GameRenderer
{

friend class GameTexture;

public:
    GameRenderer(const GameRenderer&) = delete;
    GameRenderer(GameRenderer&&) = delete;

    GameRenderer& operator= (const GameRenderer&) = delete;
    GameRenderer& operator= (GameRenderer&&) = delete;

    GameRenderer();
    ~GameRenderer();

    bool GameRendererClear();
    bool GameRendererCopy(const GameTexture& texture, const GameRect& srcRect, const GameRect& destRect, const double rotation);
    bool GameRendererCopyAll(const GameTexture& texture, const GameRect& srcRect, const double rotation);
    void GameRendererPresent();
    bool GameRendererDrawLine(const GameVector& originPoint, const GameVector& destPoint, const SDL_Color& lineColor);
    bool GameRendererDrawRect(const GameRect& rect, const SDL_Color& color);

private:
    SDL_Renderer* rendererSDLPtr;
};