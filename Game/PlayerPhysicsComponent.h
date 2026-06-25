#pragma once
#include "PhysicsComponent.h"

class PlayerPhysicsComponent : public PhysicsComponent
{
 public:
    void Update(GameEntity& entity, double extrapolateVal) override;
};