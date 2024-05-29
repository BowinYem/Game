#include "GameRenderer.h"
#include "GameTexture.h"
#include "GameSystems.h"
#include "GameWindow.h"
#include "GameVector.h"

GameRenderer::GameRenderer()
{
    rendererSDLPtr = SDL_CreateRenderer(GameSystems::GetWindow()->windowSDLPtr, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(rendererSDLPtr, 0xFF, 0xFF, 0xFF, 0xFF);
}

GameRenderer::~GameRenderer()
{
    SDL_DestroyRenderer(rendererSDLPtr);
}

bool GameRenderer::GameRendererClear()
{
    return !(SDL_RenderClear(rendererSDLPtr));
}

 bool GameRenderer::GameRendererCopy(const GameTexture& texture, const SDL_Rect& srcRect, const SDL_Rect& destRect, const double rotation)
 {
    SDL_FRect destFRect = {destRect.x, destRect.y, destRect.h, destRect.w};
    return !(SDL_RenderCopyExF(rendererSDLPtr, texture.textureSDLPtr, &srcRect, &destFRect, rotation, nullptr, SDL_FLIP_NONE));
 }

void GameRenderer::GameRendererPresent()
{
    SDL_SetRenderDrawColor(rendererSDLPtr, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderPresent(rendererSDLPtr);
}

bool GameRenderer::GameRendererDrawLine(const GameVector& originPoint, const GameVector& destPoint, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(rendererSDLPtr, color.r, color.g, color.b, color.a);
    return SDL_RenderDrawLineF(rendererSDLPtr, originPoint.x, originPoint.y, destPoint.x, destPoint.y);
}
