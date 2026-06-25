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
    virtual void Update(GameEntity& entity, double extrapolateVal) = 0;

public:
    double xVelocity = defaultXVelocity;
    double yVelocity = defaultYVelocity;
    double rotationVelocity = defaultRotateVelocity; 
};