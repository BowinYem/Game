#include "CollisionSystem.h"
#include "GameSystems.h"
#include <iostream>

void CollisionSystem::OnNotify(GameEntity& entity, const std::shared_ptr<const Event> e)
{
    if(e->eventType == EventType::CollisionEvent)
    {
        const auto collisionEvent = std::static_pointer_cast<const CollisionEvent>(e);
        switch(collisionEvent->senderType)
        {
            case CollisionEnum::collisionPlayer:
                HandlePlayerCollision(entity, collisionEvent);
                break;

            case CollisionEnum::collisionProjectile:
                HandleProjectileCollision(entity, collisionEvent);
                break;

            case CollisionEnum::collisionEnemy:
                HandleEnemyCollision(entity, collisionEvent);
                break;

            case CollisionEnum::collisionCamera:
                HandleCameraCollision(entity, collisionEvent);
                break;
        }        
    }
}

void CollisionSystem::HandlePlayerCollision(GameEntity& playerEntity, const std::shared_ptr<const CollisionEvent> e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionEnemy:
            //std::cout << "Player has collided with an enemy\n";
            break;

        case CollisionEnum::collisionBoundary:
            BoundaryBlock(playerEntity);
            break;
    }
}

void CollisionSystem::HandleProjectileCollision(GameEntity& projectileEntity, const std::shared_ptr<const CollisionEvent> e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionEnemy:
            //std::cout << "Projectile has collided with an enemy\n";
            break;

        case CollisionEnum::collisionBoundary:
            static_cast<ProjectileEntity&>(projectileEntity).ProjectileDespawnCheck();
            break;
    }
}

void CollisionSystem::HandleEnemyCollision(GameEntity& enemyEntity, const std::shared_ptr<const CollisionEvent> e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionPlayer:
            //std::cout << "Enemy has collided with the player\n";
            break;

        case CollisionEnum::collisionBoundary:
            BoundaryBlock(enemyEntity);
            break;
    }
}

void CollisionSystem::HandleCameraCollision(GameEntity& cameraEntity, const std::shared_ptr<const CollisionEvent> e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionBoundary:
            switch(GameGlobals::StartingCameraType)
            {
                case CameraTypeEnum::DebugCamera:
                case CameraTypeEnum::PlayerCamera:
                    BoundaryBlock(cameraEntity);
                    break;
            }
    }
}

void CollisionSystem::BoundaryBlock(GameEntity& entity)
{
    GameRect& collisionBox = entity.GetCollisionBox();
    GameVector& currPosition = entity.physicsState.currPosition;

    if(collisionBox.x < 0)
        { currPosition.x = collisionBox.x =  0; }

    if (collisionBox.y < 0)
        { currPosition.y = collisionBox.y = 0; }

    if(collisionBox.x > (GameGlobals::GameLevelWidth - collisionBox.w))
        { currPosition.x = collisionBox.x = (GameGlobals::GameLevelWidth - collisionBox.w); }
    
    if (collisionBox.y > (GameGlobals::GameLevelHeight - collisionBox.h))    
        { currPosition.y = collisionBox.y = (GameGlobals::GameLevelHeight - collisionBox.h); }
}



