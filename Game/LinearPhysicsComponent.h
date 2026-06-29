#pragma once
#include "PhysicsComponent.h"

class LinearPhysicsComponent : PhysicsComponent
{
public:
    void Update(GameEntity& entity, double extrapolateVal) override;    
};