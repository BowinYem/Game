#include "PhysicsComponent.h"
#include "GameEntity.h"
#include "GameVector.h"
#include "GameSystems.h"
#include "GameRenderer.h"
#include <math.h>

constexpr double PI = 3.14159265358979323846;

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
    float radians = entity.rotation * (PI / 180);
    GameVector destPos { entity.position.x + (cos(radians)), entity.position.y + (sin(radians)) };
 
    GameVector direction = destPos - entity.position;
    direction.Normalize();

    GameVector destPos2 = entity.position + GameVector{200 * direction.x, 200 * direction.y};

    
    GameSystems::GetRenderer()->GameRendererDrawLine(entity.position, destPos2, {0xFF, 0x00, 0x00, 0xFF});
    GameSystems::GetRenderer()->GameRendererDrawLine(entity.position, destPos, {0x00, 0xFF, 0x00, 0xFF});

    entity.position.x += entity.xVelocity * direction.x;
    entity.position.y += entity.yVelocity * direction.y;
    entity.rotation += entity.rotationVelocity;
}

   ////////////// Velocity, trajectory and direction  ////////////////


    /*
    https://stackoverflow.com/questions/1571294/line-equation-with-angle

    Solution:    
    x2 = x1 + (L * cos(a))
    y2 = y1 + (L * sin(a))

        *where L is length
        *do we even need to supply an L if we need a unit vector?
    */
   
    //////////////////////////////////////////