#include "GameRenderer.h"
#include "GameTexture.h"
#include "GameSystems.h"

GameRenderer::GameRenderer()
{
    renderer = SDL_CreateRenderer(GameSystems::GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

GameRenderer::~GameRenderer()
{
    SDL_DestroyRenderer(renderer);
}

bool GameRenderer::GameRendererClear()
{
    return !(SDL_RenderClear(renderer));
}

 bool GameRenderer::GameRendererCopy(const GameTexture& texture, const SDL_Rect& srcRect, const SDL_Rect& destRect)
 {
    return !(SDL_RenderCopy(renderer, texture.texture, &srcRect, &destRect));
 }

void GameRenderer::GameRendererPresent()
{
    SDL_RenderPresent(renderer);
}