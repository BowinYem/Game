#pragma once
#include "CollisionComponent.h"

class PlayerCollisionComponent : public CollisionComponent
{
 public:
    PlayerCollisionComponent(const SDL_Rect& collisionBox_);
    void detectCollisions(GameEntity& entity) override;
};