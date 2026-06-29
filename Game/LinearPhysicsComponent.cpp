#include "LinearPhysicsComponent.h"
#include "GameEntity.h"

void LinearPhysicsComponent::Update(GameEntity& entity, double extrapolateVal)
{
    auto& entPhyState = entity.physicsState;
    entPhyState.prevPosition = entPhyState.currPosition;
    entPhyState.currPosition.x += (((+entity.moveDirX) * xVelocity) * extrapolateVal);
    entPhyState.currPosition.y += (((+entity.moveDirY) * yVelocity) * extrapolateVal);
}
