#include "CollisionSystem.h"
#include <iostream>

void CollisionSystem::onNotify(const GameEntity& entity, const std::shared_ptr<Event> const e)
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

void CollisionSystem::handlePlayerCollision(const GameEntity& playerEntity, const std::shared_ptr<CollisionEvent> const e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionEnemy:
            std::cout << "Player has collided with an enemy\n";
            break;
    }
}

void CollisionSystem::handleProjectileCollision(const GameEntity& projectileEntity, const std::shared_ptr<CollisionEvent> const e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionEnemy:
            std::cout << "Projectile has collided with an enemy\n";
            break;
    }
}

void CollisionSystem::handleEnemyCollision(const GameEntity& enemyEntity, const std::shared_ptr<CollisionEvent> const e)
{
    switch(e->otherType)
    {
        case CollisionEnum::collisionPlayer:
            std::cout << "Enemy has collided with the player\n";
            break;
    }
}



