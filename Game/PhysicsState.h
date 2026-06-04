#pragma once
#include "GameVector.h"

class PhysicsState
{
public:
    PhysicsState() = default;
    PhysicsState(GameVector initPosition, double initRotation = 0.0); 

    GameVector currPosition;
    GameVector prevPosition;
    double currRotation;
    double prevRotation;
};