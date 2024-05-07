#include "SpriteComponent.h"
#include "GameRenderer.h"
#include <SDL_image.h>


static const Uint8 CHROMA_KEY_COLOR_R = 0;
static const Uint8 CHROMA_KEY_COLOR_G = 255;
static const Uint8 CHROMA_KEY_COLOR_B = 255;

static const Uint8 SPRITE_SHEET_SRC_X = 0;
static const Uint8 SPRITE_SHEET_SRC_Y = 0;

SpriteComponent::SpriteComponent(const std::string& FilePath) 
{
    SDL_Surface* LoadSurface = IMG_Load(FilePath.c_str());
    SDL_SetColorKey(LoadSurface, SDL_TRUE, SDL_MapRGB(LoadSurface->format, CHROMA_KEY_COLOR_R, CHROMA_KEY_COLOR_G, CHROMA_KEY_COLOR_B));
    SpriteSheet = SDL_CreateTextureFromSurface(GameRenderer, LoadSurface);
    SpriteSourceRect = {0, 0, LoadSurface->w, LoadSurface->h};

    // Free resources here
    SDL_FreeSurface(LoadSurface);
    LoadSurface = nullptr;
}

// Every tick, copy the sprite onto the buffer
void SpriteComponent::Update()
{
    // coords 300/300 are temporary - we might get these from the entity class containing this component
    SDL_Rect DestRect = { 300, 300, SpriteSourceRect.w, SpriteSourceRect.h };
    SDL_RenderCopy(GameRenderer, SpriteSheet, &SpriteSourceRect, &DestRect);
}