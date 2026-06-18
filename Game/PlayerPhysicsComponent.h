#pragma once
#include "PhysicsComponent.h"

class PlayerPhysicsComponent : public PhysicsComponent
{
 public:
    PlayerPhysicsComponent(SDL_Rect& collisionBox);
    virtual void Update(GameEntity& entity, double extrapolateVal) override;
};