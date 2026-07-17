#include "CollisionSystem.h"
#include "GameSystems.h"
#include <iostream>

void CollisionSystem::onNotify(GameEntity& entity, const std::shared_ptr<Event> const e)
{
    if(e->eventType == EventType::CollisionEvent)
    {
        auto collisionEvent = std::static_pointer_cast<CollisionEvent>(e);
        switch(collisionEvent->senderType)
        {
            case CollisionEnum::collisionPlayer:
                handlePlayerCollision(entity, collisionEvent);
                break;

            case CollisionEnum::collisionProjectile:
                handleProjectileCollision(entity, collisionEvent);
                break;

            case CollisionEnum::collisionEnemy:
                handleEnemyCollision(entity, collisionEvent);
                break;
        }
        
    }
}

void CollisionSystem::handlePlayerCollision(GameEntity& playerEntity, const std::shared_ptr<CollisionEvent> const e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionEnemy:
            // std::cout << "Player has collided with an enemy\n";
            break;

        case CollisionEnum::collisionBoundary:
            const SDL_Rect& collisionBox = playerEntity.GetCollisionBox();
            if(collisionBox.x < 0)                                      { playerEntity.physicsState.currPosition.x = 0; }
            if(collisionBox.x > (GameGlobals::GameLevelWidth - collisionBox.w))      { playerEntity.physicsState.currPosition.x = (GameGlobals::GameLevelWidth - collisionBox.w); }
            
            if (collisionBox.y < 0)                                     { playerEntity.physicsState.currPosition.y = 0; }
            if (collisionBox.y > (GameGlobals::GameLevelHeight - collisionBox.h))    { playerEntity.physicsState.currPosition.y = (GameGlobals::GameLevelHeight - collisionBox.h); }
            break;
    }
}

void CollisionSystem::handleProjectileCollision(GameEntity& projectileEntity, const std::shared_ptr<CollisionEvent> const e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionEnemy:
            // std::cout << "Projectile has collided with an enemy\n";
            break;
    }
}

void CollisionSystem::handleEnemyCollision(GameEntity& enemyEntity, const std::shared_ptr<CollisionEvent> const e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionPlayer:
            // std::cout << "Enemy has collided with the player\n";
            break;
    }
}



