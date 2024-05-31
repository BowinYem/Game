#include "SpriteComponent.h"
#include "GameEntity.h"
#include "GameTexture.h"
#include "GameSystems.h"
#include "GameRenderer.h"

SpriteComponent::SpriteComponent(const std::string& filePath) 
{
    spriteSheet = std::make_unique<GameTexture>(filePath);
    srcRect = {0, 0, spriteSheet->width, spriteSheet->height};
}

SpriteComponent::~SpriteComponent()
{
    // Do something here?
}

// Every tick, copy the sprite onto the buffer
void SpriteComponent::Update(GameEntity& entity)
{
    SDL_Rect destRect = { entity.position.x + offsetX, entity.position.y + offsetY, srcRect.w, srcRect.h };
    GameSystems::GetRenderer()->GameRendererCopy(*spriteSheet, srcRect, destRect, entity.rotation);
}

