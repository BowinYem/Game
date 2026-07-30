#pragma once
#include "CollisionComponent.h"
#include "GameRect.h"

class PlayerCollisionComponent : public CollisionComponent
{
 public:
    PlayerCollisionComponent(const GameRect& collisionBox_);
    void DetectCollisions(GameEntity& entity) override;
};