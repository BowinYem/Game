#pragma once
#include "GameTexture.h"
#include "string.h" 

class GameBackground
{
public:
    GameBackground(const std::string& filePath);
    void Update();
    SDL_FRect destRect;     

private:
    GameTexture bgTexture;

};