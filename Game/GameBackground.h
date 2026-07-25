#pragma once
#include "GameTexture.h"
#include "string.h" 
#include "SDL_rect.h"

class GameBackground
{
public:
    GameBackground(const std::string& filePath);
    void Update();

private:
    SDL_FRect destRect;     
    GameTexture bgTexture;
};
