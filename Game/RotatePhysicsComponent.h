#pragma once
#include "PhysicsComponent.h"
#include "GameEntity.h"

class RotatePhysicsComponent : public PhysicsComponent
{
 public:
    RotatePhysicsComponent(const double xVelocity_ = 0, const double yVelocity_ = 0, const double rotationVelocity_ = 0);

    void Update(GameEntity& entity, const double dt) override;
};
