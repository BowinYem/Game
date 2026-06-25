#include "PlayerPhysicsComponent.h"
#include "GameEntity.h"
#include <cmath>

void PlayerPhysicsComponent::Update(GameEntity& entity, double extrapolateVal)
{
    auto& entPhyState = entity.physicsState;
    
    GameVector forwardDirection = entity.GetForwardDirection();
    entPhyState.prevPosition = entPhyState.currPosition;
    entPhyState.currPosition.x += (((+entity.moveDir) * xVelocity) * extrapolateVal) * forwardDirection.x;
    entPhyState.currPosition.y += (((+entity.moveDir) * yVelocity) * extrapolateVal) * forwardDirection.y;

    entPhyState.prevRotation = entPhyState.currRotation;
    entPhyState.currRotation += (((+entity.rotateDir) * rotationVelocity) * extrapolateVal);
    entPhyState.currRotation = std::fmod(entPhyState.currRotation, 360.0f); // Wrap around so the rotation value doesn't go beyond 360 degrees
}
