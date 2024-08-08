#include "GameEntity.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GameMath.h"
#include "GameSystems.h"
#include "GameRenderer.h"
#include <iostream>


GameEntity::GameEntity(std::shared_ptr<SpriteComponent> spriteComp_, std::shared_ptr<InputComponent> inputComp_, std::shared_ptr<PhysicsComponent> physicsComp_, EntityType entityType_, GameVector spawnLocation) 
    : spriteComp{spriteComp_}, inputComp{inputComp_}, physicsComp{physicsComp_}, entityType{entityType_}, position{spawnLocation}
{
    //...
}

void GameEntity::Update()
{
    if(inputComp)
        { inputComp->Update(*this); }

    if(physicsComp)
        { physicsComp->Update(*this); }

    if(spriteComp)
        { spriteComp->Update(*this); } 
    
    #ifdef COLLISION_DEBUG_MODE
    GameSystems::GetRenderer()->GameRendererDrawRect(physicsComp->collisionBox, GameSystems::testColor);
    #endif // COLLISION_DEBUG_MODE
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


void GameEntity::SetSpriteComponent(std::shared_ptr<SpriteComponent> spriteComp_)
{
    spriteComp = spriteComp_;
}

void GameEntity::SetInputComponent(std::shared_ptr<InputComponent> inputComp_)
{
    inputComp = inputComp_;
}

void GameEntity::SetPhysicsComponent(std::shared_ptr<PhysicsComponent> physicsComp_)
{
    physicsComp = physicsComp_;
}
 
const SDL_Rect& GameEntity::GetCollisionBox()
{
    return physicsComp->collisionBox; 
}