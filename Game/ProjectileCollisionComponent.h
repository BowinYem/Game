#pragma once
#include "CollisionComponent.h"

class ProjectileCollisionComponent : public CollisionComponent
{
public:
    ProjectileCollisionComponent(const SDL_Rect& collisionBox_);  
private:
    void detectCollisions(GameEntity& entity) override;
};
