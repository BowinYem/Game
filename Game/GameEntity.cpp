#include "GameEntity.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GameMath.h"
#include <iostream>



GameEntity::GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_, std::unique_ptr<InputComponent> InputComp_, std::unique_ptr<PhysicsComponent> PhysicsComp_, GameVector SpawnLocation) 
    : SpriteComp{std::move(SpriteComp_)}, InputComp{std::move(InputComp_)}, PhysicsComp{std::move(PhysicsComp_)}, position{SpawnLocation}
{
    // Do this to center the entity postion onto the center of the sprite
    SpriteComp->offsetX = -(SpriteComp->srcRect.w / 2);
    SpriteComp->offsetY = -(SpriteComp->srcRect.h / 2);
}

GameEntity::~GameEntity()
{
    // Destructor body...
}

void GameEntity::Update()
{
    if(InputComp)
        { InputComp->Update(*this); }

    if(PhysicsComp)
        { PhysicsComp->Update(*this); }

    if(SpriteComp)
        { SpriteComp->Update(*this); } 
    
}

GameVector GameEntity::GetForwardDirection()
{
    /*
        This function returns a directional vector representing the forward direction of this entity. 
        The forward direction of an entity is dependent on it's current rotation. For example, if an
        entity has a rotation of 0, it's foward vector will be going directly to the right. 
    */

    /*
        These equations will give the endpoint of a line, given that you have a starting point (x1, y2), 
        an angle (a) representing the direction of the line, and the length of the line (L):

            x2 = x1 + (L * cos(a))
            y2 = y1 + (L * sin(a))

        Using these equations and the current position and angle of our entity, we can figure out
        what consitutes as a forward direction for our entity.

        Normally we'd normalize this, but since we're implicity using a length of 1, there's no need to. 

        Source: https://stackoverflow.com/questions/1571294/line-equation-with-angle
    */

    float rotationRadians = GameMath::DegreesToRadians(rotation);
    GameVector destPos { position.x + (cos(rotationRadians)), position.y + (sin(rotationRadians)) }; 
    return destPos - position;
}




 