#include "GameBackground.h"
#include "GameSystems.h"

GameBackground::GameBackground(const std::string& filePath) : bgTexture{filePath}, 
    destRect{0, 0, GameGlobals::GameLogicalWidth, GameGlobals::GameLogicalHeight}
{
   //...
}

void GameBackground::Update()
{
    if(GameSystems::camera)
        { GameSystems::GetRenderer()->GameRendererCopy(bgTexture, GameSystems::camera->cameraRect, destRect, 0); }
}