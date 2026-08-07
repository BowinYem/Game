#include "GameEntity.h"
#include "GameMath.h"
#include "GameSystems.h"
#include "GameRenderer.h"


GameEntity::GameEntity(const std::shared_ptr<SpriteComponent> spriteComp_, 
                       const std::shared_ptr<InputComponent> inputComp_, 
                       const std::shared_ptr<PhysicsComponent> physicsComp_, 
                       const std::shared_ptr<CollisionComponent> collisionComp_, 
                       const GameVector& spawnLocation) 

    : spriteComp{spriteComp_}, inputComp{inputComp_}, physicsComp{physicsComp_}, collisionComp{collisionComp_}, 
      renderPosition{spawnLocation}, physicsState{renderPosition}
{
    //...
}

void GameEntity::UpdatePhysics(const double dt)
{
    if(physicsComp)
        { physicsComp->Update(*this, dt); }
}

void GameEntity::UpdateInput()
{
    if(inputComp)
        { inputComp->Update(*this); }
}

void GameEntity::UpdateSprite(const double alpha)
{
    if(spriteComp)
        { spriteComp->Update(*this, alpha); } 

    
    #ifdef COLLISION_DEBUG_MODE
    if(collisionComp)
    {
        GameRect collisionRect = collisionComp->collisionBox;
        collisionRect.x =  collisionComp->collisionBox.x - GameSystems::camera->cameraRect.x;
        collisionRect.y =  collisionComp->collisionBox.y - GameSystems::camera->cameraRect.y; 

        GameSystems::GetRenderer()->GameRendererDrawRect(collisionRect, GameGlobals::TestColor);
    }
    #endif // COLLISION_DEBUG_MODE
}

void GameEntity::UpdateCollision()
{
    if(collisionComp)
    { 
        collisionComp->Update(*this); 
    }
}

GameVector GameEntity::GetForwardDirection() const
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

    float rotationRadians = GameMath::DegreesToRadians(renderRotation);
    GameVector destPos { renderPosition.x + (cos(rotationRadians)), renderPosition.y + (sin(rotationRadians)) }; 
    return destPos - renderPosition;
}

inline void GameEntity::SetSpriteComponent(const std::shared_ptr<SpriteComponent> spriteComp_)
{
    spriteComp = spriteComp_;
}

inline void GameEntity::SetInputComponent(const std::shared_ptr<InputComponent> inputComp_)
{
    inputComp = inputComp_;
}

inline void GameEntity::SetPhysicsComponent(const std::shared_ptr<PhysicsComponent> physicsComp_)
{
    physicsComp = physicsComp_;
}
 
inline void GameEntity::SetCollisionComponent(const std::shared_ptr<CollisionComponent> collisionComp_)
{
    collisionComp = collisionComp_;
}

const GameRect& GameEntity::GetCollisionBox()
{
    if(physicsComp)
        { return collisionComp->collisionBox; }
}

const GameRect& GameEntity::GetSpriteDest()
{
    if(spriteComp)
        { return spriteComp->destRect; }
}
