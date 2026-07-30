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

 bool GameRenderer::GameRendererCopy(const GameTexture& texture, const GameRect& srcRect, const GameRect& destRect, const double rotation)
 {
    SDL_Rect renderSrcRect = srcRect.GetIRect();
    SDL_FRect renderDestRect = destRect.GetFRect();
    return !(SDL_RenderCopyExF(rendererSDLPtr, texture.textureSDLPtr, &renderSrcRect, &renderDestRect, rotation, nullptr, SDL_FLIP_NONE));
 }

bool GameRenderer::GameRendererCopyAll(const GameTexture& texture, const GameRect& srcRect, const double rotation)
{
    SDL_Rect renderSrcRect = srcRect.GetIRect();
    return !(SDL_RenderCopyExF(rendererSDLPtr, texture.textureSDLPtr, &renderSrcRect, nullptr, rotation, nullptr, SDL_FLIP_NONE));
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

bool GameRenderer::GameRendererDrawRect(const GameRect& rect, const SDL_Color& color)
{
    SDL_Rect renderRect = rect.GetIRect();
    SDL_SetRenderDrawColor(rendererSDLPtr, color.r, color.g, color.b, color.a);
    return SDL_RenderDrawRect(rendererSDLPtr, &renderRect);
}
