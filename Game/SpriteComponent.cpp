#include "SpriteComponent.h"
#include "GameEntity.h"
#include "GameTexture.h"
#include "GameSystems.h"
#include "GameRenderer.h"

SpriteComponent::SpriteComponent(const std::string& FilePath) 
{
    SpriteSheet = std::make_unique<GameTexture>(FilePath);
    srcRect = {0, 0, SpriteSheet->width, SpriteSheet->height};
}

SpriteComponent::~SpriteComponent()
{
    // Do something here?
}

// Every tick, copy the sprite onto the buffer
void SpriteComponent::Update(GameEntity& Entity)
{
    SDL_Rect destRect = { Entity.position.x, Entity.position.y, srcRect.w, srcRect.h };
    GameSystems::GetRenderer()->GameRendererCopy(*SpriteSheet, srcRect, destRect, Entity.rotation);
}

