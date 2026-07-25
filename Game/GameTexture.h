// C wrapper class

#pragma once
#include <SDL.h>
#include <string>
#include "GameRenderer.h"

class GameTexture
{

friend class GameRenderer;

public:
    GameTexture(const std::string& filePath);
    ~GameTexture();

    uint16_t width;
    uint16_t height;

private:
    SDL_Texture* textureSDLPtr;
};