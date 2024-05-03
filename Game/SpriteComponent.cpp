#include "SpriteComponent.h"
#include "GameRenderer.h"
#include <SDL_image.h>


static const Uint8 CHROMA_KEY_COLOR_R = 255;
static const Uint8 CHROMA_KEY_COLOR_G = 255;
static const Uint8 CHROMA_KEY_COLOR_B = 255;

SpriteComponent::SpriteComponent(const std::string& FilePath, const SDL_Rect& SheetSize_, const SDL_Rect& SpriteSize_, Uint8 TotalSprites_) :
    SheetSize(SheetSize_), SpriteSize(SpriteSize_), TotalSprites(TotalSprites_)
{
    SDL_Surface* LoadSurface = IMG_Load(FilePath.c_str());
    SDL_SetColorKey(LoadSurface, SDL_TRUE, SDL_MapRGB(LoadSurface->format, CHROMA_KEY_COLOR_R, CHROMA_KEY_COLOR_G, CHROMA_KEY_COLOR_B));
    //SpriteSheet = SDL_CreateTextureFromSurface()
}