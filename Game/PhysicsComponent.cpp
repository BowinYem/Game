#include "PhysicsComponent.h"
#include "GameEntity.h"
#include "GameVector.h"
#include "GameSystems.h"
#include "GameRenderer.h"
#include <math.h>
#include <iostream>

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
    entity.Position.x += entity.xVelocity * forwardDirection.x;
    entity.Position.y += entity.yVelocity * forwardDirection.y;

    entity.Rotation += entity.RotationVelocity;
    entity.Rotation %= 360;
}
