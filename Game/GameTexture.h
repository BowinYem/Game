// C wrapper class

#pragma once
#include <SDL.h>
#include <string>

class GameTexture
{
public:
    GameTexture(const std::string& FilePath);

    ~GameTexture();

    bool RenderCopy(const SDL_Rect& SrcRect, const SDL_Rect& DestRect);

public:
    static uint8_t chromaKeyR;
	static uint8_t chromaKeyG;
	static uint8_t chromaKeyB;

    uint16_t width;
    uint16_t height;

private:
    SDL_Texture* Texture;
};

