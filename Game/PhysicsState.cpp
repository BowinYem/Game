#include "PhysicsState.h"

PhysicsState::PhysicsState(const GameVector& initPosition, const double initRotation) : currPosition{initPosition}, prevPosition{initPosition}, 
    currRotation{initRotation}, prevRotation{initRotation} 
    { 
        /*...*/ 
    }