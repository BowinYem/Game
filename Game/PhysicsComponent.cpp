#include "PhysicsComponent.h"
#include "GameEntity.h"
#include "GameVector.h"
#include "GameSystems.h"

PhysicsComponent::PhysicsComponent()
{
    //...Constructor body
}

PhysicsComponent::~PhysicsComponent()
{
    //...Destructor body
}

void PhysicsComponent::Update(GameEntity& entity)
{
    GameVector forwardDirection = entity.GetForwardDirection();
    entity.position.x += entity.xVelocity * forwardDirection.x;
    entity.position.y += entity.yVelocity * forwardDirection.y;

    entity.rotation += entity.rotationVelocity;
    entity.rotation %= 360; // Wrap around so the rotation value doesn't go beyond 360 degrees
}
