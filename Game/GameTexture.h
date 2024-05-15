// C wrapper class

#pragma once
#include <SDL.h>
#include <string>

class GameTexture
{

friend class GameRenderer;

public:
    GameTexture(const std::string& FilePath);

    ~GameTexture();

public:
    uint16_t width;
    uint16_t height;

private:
    SDL_Texture* texture;
};

