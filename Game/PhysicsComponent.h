#pragma once
#include "GameVector.h"

class GameEntity;

class PhysicsComponent
{
 public:
    PhysicsComponent();
    ~PhysicsComponent();
    void Update(GameEntity& entity);

private:

};