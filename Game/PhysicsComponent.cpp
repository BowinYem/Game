#include "PhysicsComponent.h"
#include "GameEntity.h"
#include "GameVector.h"
#include "GameSystems.h"
#include "GameRenderer.h"

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

