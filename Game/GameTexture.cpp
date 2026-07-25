#include "GameTexture.h"
#include "GameSystems.h"
#include <SDL_image.h>

GameTexture::GameTexture(const std::string& filePath)
{
    SDL_Surface* LoadSurface = IMG_Load(filePath.c_str());
    SDL_SetColorKey(LoadSurface, SDL_TRUE, SDL_MapRGB(LoadSurface->format, GameGlobals::SpriteChromaColor.r, GameGlobals::SpriteChromaColor.g, GameGlobals::SpriteChromaColor.b));
    textureSDLPtr = SDL_CreateTextureFromSurface(GameSystems::GetRenderer()->rendererSDLPtr, LoadSurface);
    width = LoadSurface->w;
    height = LoadSurface->h;

    // Free resources here
    SDL_FreeSurface(LoadSurface);
    LoadSurface = nullptr;
}

GameTexture::~GameTexture()
{
    SDL_DestroyTexture(textureSDLPtr);
    textureSDLPtr = nullptr;
}

