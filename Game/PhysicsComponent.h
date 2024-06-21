#pragma once
#include "GameVector.h"

class GameEntity;

class PhysicsComponent
{
 public:
    PhysicsComponent();
    PhysicsComponent(SDL_Rect& collisionBox_);
    ~PhysicsComponent();
    void Update(GameEntity& entity);

public:
    SDL_Rect collisionBox;
};