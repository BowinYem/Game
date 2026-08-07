#pragma once
#include "GameEntity.h"

class GameEntity;

class PhysicsComponent
{
 public:
    PhysicsComponent(const double xVelocity_ = 0, const double yVelocity_ = 0, const double rotationVelocity_ = 0);

    virtual void Update(GameEntity& entity, const double dt) = 0;

    double xVelocity; 
    double yVelocity;
    double rotationVelocity;
};
