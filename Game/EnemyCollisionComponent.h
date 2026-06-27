#pragma once
#include "CollisionComponent.h"

class EnemyCollisionComponent : public CollisionComponent
{
public:
    EnemyCollisionComponent(const SDL_Rect& collisionBox_);
    void detectCollisions(GameEntity& testEntity) override;

};