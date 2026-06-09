#pragma once
#include "GameVector.h"
#include "SDL.h"

constexpr double defaultXVelocity = 100;
constexpr double defaultYVelocity = 100;
constexpr double defaultRotateVelocity = 100; 

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
    double xVelocity = defaultXVelocity;
    double yVelocity = defaultYVelocity;
    double rotationVelocity = defaultRotateVelocity; 
;
};