#pragma once
#include "CollisionComponent.h"
#include "GameRect.h"

class ProjectileCollisionComponent : public CollisionComponent
{
public:
    ProjectileCollisionComponent(const GameRect& collisionBox_);  
    
private:
    void DetectCollisions(GameEntity& entity) override;
};
