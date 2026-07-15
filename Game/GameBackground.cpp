#include "GameBackground.h"
#include "GameSystems.h"
#include "SDL_rect.h"

GameBackground::GameBackground(const std::string& filePath) : bgTexture{filePath}
{
    destRect.x = 0;
    destRect.y = 0;
}

void GameBackground::Update()
{
    if(GameSystems::camera)
    {   
        destRect.w =  GameLogicalWidth;
        destRect.h =  GameLogicalHeight;
        GameSystems::GetRenderer()->GameRendererCopy(bgTexture, GameSystems::camera->getCameraRect(), destRect, 0);
    }
}