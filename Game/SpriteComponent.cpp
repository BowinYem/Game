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
void SpriteComponent::Update(GameEntity& entity, double alpha)
{
    interpolate(entity, alpha);
    destRect.x =  entity.renderPosition.x;
    destRect.y =  entity.renderPosition.y; 
    destRect.w =  srcRect.w;
    destRect.h =  srcRect.h;
    GameSystems::GetRenderer()->GameRendererCopy(*spriteSheet, srcRect, destRect, entity.renderRotation);
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

void SpriteComponent::interpolate(GameEntity& entity, double alpha)
{
		entity.renderPosition  = (entity.physicsState.currPosition * alpha) + (entity.physicsState.prevPosition * (1.0 - alpha));
        entity.renderRotation  = (entity.physicsState.currRotation * alpha) + (entity.physicsState.prevRotation * (1.0 - alpha));
}