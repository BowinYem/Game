#pragma once
#include "GameVector.h"
#include "SDL.h"

class GameEntity;

class PhysicsComponent
{
 public:
    PhysicsComponent();
    PhysicsComponent(SDL_Rect& collisionBox_);
    ~PhysicsComponent();
    void Update(GameEntity& entity, double extrapolateVal);

public:
    SDL_Rect collisionBox;
};