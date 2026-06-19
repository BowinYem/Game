#include "SpriteComponent.h"
#include "GameEntity.h"
#include "GameTexture.h"
#include "GameSystems.h"
#include "GameRenderer.h"
#include <cmath>

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
        // Naive LERP
		entity.renderPosition  = (entity.physicsState.currPosition * alpha) + (entity.physicsState.prevPosition * (1.0 - alpha));
        
        // Shortest Path Algorithm Formula for Rotational Interpolation
        auto diff = entity.physicsState.currRotation - entity.physicsState.prevRotation;
        diff = diff - (360.0 * std::floor((diff + 180.0)/360.0)); 
        entity.renderRotation = entity.physicsState.prevRotation + (diff * alpha);
}