#include "PhysicsState.h"

PhysicsState::PhysicsState(GameVector initPosition, double initRotation) : currPosition{initPosition}, prevPosition{initPosition}, 
    currRotation{initRotation}, prevRotation{initRotation} { }