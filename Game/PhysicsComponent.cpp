#include "PhysicsComponent.h"
#include "GameEntity.h"
#include "GameVector.h"
#include "GameSystems.h"
#include "GameRenderer.h"
#include <cmath>

PhysicsComponent::PhysicsComponent()
{
    collisionBox.h = 0;
    collisionBox.w = 0;
    collisionBox.x = 0;
    collisionBox.y = 0;
    //...Constructor body
}

PhysicsComponent::PhysicsComponent(SDL_Rect& collisionBox_) 
{
   //...Constructor body
   collisionBox.h = collisionBox_.h;
   collisionBox.w = collisionBox_.w;
   collisionBox.x = collisionBox_.x;
   collisionBox.y = collisionBox_.y;
}


PhysicsComponent::~PhysicsComponent()
{
    //...Destructor body
}

void PhysicsComponent::Update(GameEntity& entity, double extrapolateVal)
{
    auto& entPhyState = entity.physicsState;
    
    GameVector forwardDirection = entity.GetForwardDirection();
    entPhyState.prevPosition = entPhyState.currPosition;
    entPhyState.currPosition.x += (entity.xVelocity * extrapolateVal) * forwardDirection.x;
    entPhyState.currPosition.y += (entity.yVelocity * extrapolateVal) * forwardDirection.y;

    entPhyState.prevRotation = entPhyState.currRotation;
    entPhyState.currRotation += (entity.rotationVelocity * extrapolateVal);
    entPhyState.currRotation = std::fmod(entPhyState.currRotation, 360.0f); // Wrap around so the rotation value doesn't go beyond 360 degrees
    
    collisionBox.x = entity.renderPosition.x;
    collisionBox.y = entity.renderPosition.y;
}

 