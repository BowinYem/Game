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

// Every tick, copy the sprite onto the buffer
void SpriteComponent::Update(GameEntity& entity)
{
    destRect.x =  entity.position.x;
    destRect.y =  entity.position.y; 
    destRect.w =  srcRect.w;
    destRect.h =  srcRect.h;
    GameSystems::GetRenderer()->GameRendererCopy(*spriteSheet, srcRect, destRect, entity.rotation);
}

SpriteComponent& SpriteComponent::operator= (SpriteComponent& otherComp)
{
    this->srcRect = otherComp.srcRect;
    this->spriteSheet = otherComp.spriteSheet;
    return *this;
}

const SDL_Rect& SpriteComponent::GetSpriteDimenisions()
{
    return srcRect;
}
