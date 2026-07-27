#include "LinearPhysicsComponent.h"

LinearPhysicsComponent::LinearPhysicsComponent(const double xVelocity_, const double yVelocity_, const double rotationVelocity_) :
    PhysicsComponent{xVelocity_, yVelocity_, rotationVelocity_}
{
    //...
}


void LinearPhysicsComponent::Update(GameEntity& entity, const double alpha)
{
    auto& entPhyState = entity.physicsState;
    entPhyState.prevPosition = entPhyState.currPosition;
    entPhyState.currPosition.x += (((+entity.moveDirX) * xVelocity) * alpha);
    entPhyState.currPosition.y += (((+entity.moveDirY) * yVelocity) * alpha);
}
