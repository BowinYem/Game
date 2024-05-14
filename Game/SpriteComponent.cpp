#include "SpriteComponent.h"
#include "GameEntity.h"
#include "GameTexture.h"

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

