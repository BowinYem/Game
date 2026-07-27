#include "RotatePhysicsComponent.h"
#include <cmath>

RotatePhysicsComponent::RotatePhysicsComponent(const double xVelocity_, const double yVelocity_, const double rotationVelocity_) :
    PhysicsComponent{xVelocity_, yVelocity_, rotationVelocity_}
{
    //...
}


void RotatePhysicsComponent::Update(GameEntity& entity, const double alpha)
{
    auto& entPhyState = entity.physicsState;
    
    const GameVector forwardDirection = entity.GetForwardDirection();
    entPhyState.prevPosition = entPhyState.currPosition;
    entPhyState.currPosition.x += (((+entity.moveDirX) * xVelocity) * alpha) * forwardDirection.x;
    entPhyState.currPosition.y += (((+entity.moveDirY) * yVelocity) * alpha) * forwardDirection.y;

    entPhyState.prevRotation = entPhyState.currRotation;
    entPhyState.currRotation += (((+entity.rotateDir) * rotationVelocity) * alpha);
    entPhyState.currRotation = std::fmod(entPhyState.currRotation, 360.0f); // Wrap around so the rotation value doesn't go beyond 360 degrees
}
