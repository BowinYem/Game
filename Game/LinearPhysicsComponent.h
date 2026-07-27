#pragma once
#include "PhysicsComponent.h"
#include "GameEntity.h"

class LinearPhysicsComponent : public PhysicsComponent
{
public:
    LinearPhysicsComponent(const double xVelocity_ = 0, const double yVelocity_ = 0, const double rotationVelocity_ = 0);

    void Update(GameEntity& entity, const double alpha) override;    
};
