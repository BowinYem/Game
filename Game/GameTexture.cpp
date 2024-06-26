#include "GameTexture.h"
#include "GameSystems.h"
#include "GameRenderer.h"
#include <SDL_image.h>

static const Uint8 CHROMA_KEY_COLOR_R = 0; 
static const Uint8 CHROMA_KEY_COLOR_G = 255;
static const Uint8 CHROMA_KEY_COLOR_B = 255;

GameTexture::GameTexture(const std::string& filePath)
{
    SDL_Surface* LoadSurface = IMG_Load(filePath.c_str());
    SDL_SetColorKey(LoadSurface, SDL_TRUE, SDL_MapRGB(LoadSurface->format, CHROMA_KEY_COLOR_R, CHROMA_KEY_COLOR_G, CHROMA_KEY_COLOR_B));
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

