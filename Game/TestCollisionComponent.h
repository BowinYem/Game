#pragma once
#include "CollisionComponent.h"

class TestCollisionComponent : public CollisionComponent
{
public:
    TestCollisionComponent(const SDL_Rect& collisionBox_);
    void detectCollisions(GameEntity& testEntity) override;

};