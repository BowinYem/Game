#include "SpriteComponent.h"
#include "GameEntity.h"
#include "GameSystems.h"
#include "GameTexture.h"
#include <SDL_image.h>


static const Uint8 CHROMA_KEY_COLOR_R = 0;
static const Uint8 CHROMA_KEY_COLOR_G = 255;
static const Uint8 CHROMA_KEY_COLOR_B = 255;

static const Uint8 SPRITE_SHEET_SRC_X = 0;
static const Uint8 SPRITE_SHEET_SRC_Y = 0;

SpriteComponent::SpriteComponent(const std::string& FilePath) 
{
    SpriteSheet = std::make_unique<GameTexture>(FilePath);
    SpriteSourceRect = {0, 0, SpriteSheet->width, SpriteSheet->height};
}

SpriteComponent::~SpriteComponent()
{
    // Do something here?
}

// Every tick, copy the sprite onto the buffer
void SpriteComponent::Update(const GameEntity& Entity)
{
    SDL_Rect DestRect = { Entity.x, Entity.y, SpriteSourceRect.w, SpriteSourceRect.h };
    SpriteSheet->RenderCopy(SpriteSourceRect, DestRect);
}

