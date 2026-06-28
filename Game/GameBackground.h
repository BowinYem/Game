#pragma once
#include "GameTexture.h"
#include "string.h" 

class GameBackground
{
public:
    GameBackground(const std::string& filePath);
    void Update();

private:
    GameTexture bgTexture;
    SDL_Rect srcRect;
    SDL_FRect destRect;     
};