#include "PlayerCollisionComponent.h"
#include "GameSystems.h"
#include "EntityPool.h"
#include "EnemyEntity.h"
#include "CollisionEvent.h"

PlayerCollisionComponent::PlayerCollisionComponent(const GameRect& collisionBox_) : CollisionComponent{collisionBox_, CollisionEnum::collisionPlayer}
{  
    //...
}

void PlayerCollisionComponent::DetectCollisions(GameEntity& entity)
{
    for(size_t i = 0; i < GameSystems::enemyPool->GetPoolSize(); ++i)
    {
        if(GameSystems::enemyPool->IsEntityInUse(i))
        {
            auto& enemy = GameSystems::enemyPool->GetEntity(i);
            bool collisionDetected = GameRect::HasIntersection(collisionBox, enemy.GetCollisionBox());
            if(collisionDetected) 
            { 
                Notify(entity, std::make_shared<CollisionEvent>(enemy, collisionType, CollisionEnum::collisionEnemy)); 
            }
        }
    }

    if((collisionBox.x < 0) || (collisionBox.x > (GameGlobals::GameLevelWidth - collisionBox.w)) ||
        (collisionBox.y < 0) || (collisionBox.y > (GameGlobals::GameLevelHeight - collisionBox.h)))
    {
        Notify(entity, std::make_shared<CollisionEvent>(entity, collisionType, CollisionEnum::collisionBoundary)); 
    }
}