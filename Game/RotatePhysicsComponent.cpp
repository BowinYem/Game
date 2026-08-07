#include "RotatePhysicsComponent.h"
#include <cmath>

RotatePhysicsComponent::RotatePhysicsComponent(const double xVelocity_, const double yVelocity_, const double rotationVelocity_) :
    PhysicsComponent{xVelocity_, yVelocity_, rotationVelocity_}
{
    //...
}


void RotatePhysicsComponent::Update(GameEntity& entity, const double dt)
{
    auto& entPhyState = entity.physicsState;
    
    const GameVector forwardDirection = entity.GetForwardDirection();
    entPhyState.prevPosition = entPhyState.currPosition;
    entPhyState.currPosition.x += (((+entity.moveDirX) * xVelocity) * dt) * forwardDirection.x;
    entPhyState.currPosition.y += (((+entity.moveDirY) * yVelocity) * dt) * forwardDirection.y;

    entPhyState.prevRotation = entPhyState.currRotation;
    entPhyState.currRotation += (((+entity.rotateDir) * rotationVelocity) * dt);
    entPhyState.currRotation = std::fmod(entPhyState.currRotation, 360.0f); // Wrap around so the rotation value doesn't go beyond 360 degrees
}
