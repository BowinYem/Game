#pragma once
#include "CollisionComponent.h"
#include "GameEntity.h"
#include "SDL.h"

class EnemyCollisionComponent : public CollisionComponent
{
public:
    EnemyCollisionComponent(const SDL_Rect& collisionBox_);
    void DetectCollisions(GameEntity& testEntity) override;

};