#pragma once
#include "GameVector.h"

class PhysicsState
{
public:
    PhysicsState(const GameVector& initPosition, const double initRotation = 0.0); 

    GameVector currPosition;
    GameVector prevPosition;
    double currRotation;
    double prevRotation;
};
