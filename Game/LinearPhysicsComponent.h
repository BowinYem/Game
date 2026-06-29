#pragma once
#include "PhysicsComponent.h"

class LinearPhysicsComponent : public PhysicsComponent
{
public:
    void Update(GameEntity& entity, double extrapolateVal) override;    
};