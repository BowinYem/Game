#pragma once
#include "PhysicsComponent.h"

class RotatePhysicsComponent : public PhysicsComponent
{
 public:
    void Update(GameEntity& entity, double extrapolateVal) override;
};