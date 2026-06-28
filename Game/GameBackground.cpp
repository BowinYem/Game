#include "GameBackground.h"
#include "GameSystems.h"
#include "SDL_rect.h"

GameBackground::GameBackground(const std::string& filePath) : bgTexture{filePath}
{
    srcRect = { 0, 0, bgTexture.width, bgTexture.height };
    destRect.x = 0;
    destRect.y = 0;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

void GameBackground::Update()
{
    GameSystems::GetRenderer()->GameRendererCopy(bgTexture, srcRect, destRect, 0);
}