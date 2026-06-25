#include "PlayerCollisionComponent.h"
#include "GameSystems.h"
#include "EntityPool.h"
#include "CollisionEvent.h"

PlayerCollisionComponent::PlayerCollisionComponent(const SDL_Rect& collisionBox_) : CollisionComponent{collisionBox_, CollisionEnum::collisionPlayer}
{  
    //...
}

void PlayerCollisionComponent::detectCollisions(GameEntity& entity)
{
    for(size_t i = 0; i < GameSystems::enemyPool->GetPoolSize(); ++i)
    {
        if(GameSystems::enemyPool->IsEntityInUse(i))
        {
            auto& enemyEntity = GameSystems::enemyPool->GetEntity(i);
            bool collisionDetected = SDL_HasIntersection(&collisionBox, &enemyEntity.GetCollisionBox());
            if(collisionDetected) 
            { 
                notify(entity, std::make_shared<CollisionEvent>(enemyEntity, collisionType, CollisionEnum::collisionEnemy)); 
            }
        }
    }
}