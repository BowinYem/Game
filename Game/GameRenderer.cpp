#include "GameRenderer.h"
#include "GameTexture.h"
#include "GameSystems.h"
#include "GameWindow.h"

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
    return !(SDL_RenderCopyEx(rendererSDLPtr, texture.textureSDLPtr, &srcRect, &destRect, rotation, nullptr, SDL_FLIP_NONE));
 }

void GameRenderer::GameRendererPresent()
{
    SDL_RenderPresent(rendererSDLPtr);
}