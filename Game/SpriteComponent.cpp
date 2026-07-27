#include "SpriteComponent.h"
#include "GameSystems.h"
#include "GameRenderer.h"
#include <cmath>

SpriteComponent::SpriteComponent(const std::string& filePath) 
{
    spriteSheet = std::make_shared<GameTexture>(filePath);
    srcRect = {0, 0, spriteSheet->width, spriteSheet->height};
}

// Every tick, copy the sprite onto the buffer
void SpriteComponent::Update(GameEntity& entity, const double alpha)
{
    interpolate(entity, alpha);
    destRect.x =  entity.renderPosition.x - GameSystems::camera->cameraRect.x;
    destRect.y =  entity.renderPosition.y - GameSystems::camera->cameraRect.y; 
    destRect.w =  srcRect.w;
    destRect.h =  srcRect.h;
    GameSystems::GetRenderer()->GameRendererCopy(*spriteSheet, srcRect, destRect, entity.renderRotation);
}

void SpriteComponent::interpolate(GameEntity& entity, const double alpha)
{
        // Naive LERP
		entity.renderPosition  = (entity.physicsState.currPosition * alpha) + (entity.physicsState.prevPosition * (1.0 - alpha));
        
        // Shortest Path Algorithm Formula for Rotational Interpolation
        auto diff = entity.physicsState.currRotation - entity.physicsState.prevRotation;
        diff = diff - (360.0 * std::floor((diff + 180.0)/360.0)); 
        entity.renderRotation = entity.physicsState.prevRotation + (diff * alpha);
}