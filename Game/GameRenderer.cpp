#include "GameRenderer.h"
#include "GameSystems.h"
#include "GameWindow.h"

GameRenderer::GameRenderer()
{
    rendererSDLPtr = SDL_CreateRenderer(GameSystems::GetWindow()->windowSDLPtr, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    SDL_SetRenderDrawColor(rendererSDLPtr, GameGlobals::FinalRenderDrawColor.r, GameGlobals::FinalRenderDrawColor.g, 
        GameGlobals::FinalRenderDrawColor.b, GameGlobals::FinalRenderDrawColor.a);

    SDL_RenderSetLogicalSize(rendererSDLPtr, GameGlobals::GameLogicalWidth, GameGlobals::GameLogicalHeight);
}

GameRenderer::~GameRenderer()
{
    SDL_DestroyRenderer(rendererSDLPtr);
}

bool GameRenderer::GameRendererClear()
{
    return !(SDL_RenderClear(rendererSDLPtr));
}

 bool GameRenderer::GameRendererCopy(const GameTexture& texture, const SDL_Rect& srcRect, const SDL_FRect& destRect, const double rotation)
 {
    return !(SDL_RenderCopyExF(rendererSDLPtr, texture.textureSDLPtr, &srcRect, &destRect, rotation, nullptr, SDL_FLIP_NONE));
 }

bool GameRenderer::GameRendererCopyAll(const GameTexture& texture, const SDL_Rect& srcRect, const double rotation)
{
    return !(SDL_RenderCopyExF(rendererSDLPtr, texture.textureSDLPtr, &srcRect, nullptr, rotation, nullptr, SDL_FLIP_NONE));
}

void GameRenderer::GameRendererPresent()
{
    SDL_SetRenderDrawColor(rendererSDLPtr, GameGlobals::FinalRenderDrawColor.r, GameGlobals::FinalRenderDrawColor.g, 
        GameGlobals::FinalRenderDrawColor.b, GameGlobals::FinalRenderDrawColor.a);

    SDL_RenderPresent(rendererSDLPtr);
}

bool GameRenderer::GameRendererDrawLine(const GameVector& originPoint, const GameVector& destPoint, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(rendererSDLPtr, color.r, color.g, color.b, color.a);
    return SDL_RenderDrawLineF(rendererSDLPtr, originPoint.x, originPoint.y, destPoint.x, destPoint.y);
}

bool GameRenderer::GameRendererDrawRect(const SDL_Rect& rect, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(rendererSDLPtr, color.r, color.g, color.b, color.a);
    return SDL_RenderDrawRect(rendererSDLPtr, &rect);
}
