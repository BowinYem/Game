#include "EnemyCollisionComponent.h"
#include "GameSystems.h"

EnemyCollisionComponent::EnemyCollisionComponent(const SDL_Rect& collisionBox_) : CollisionComponent{collisionBox_, CollisionEnum::collisionEnemy} 
{  
    //...
}

void EnemyCollisionComponent::detectCollisions(GameEntity& testEntity)
{
    if(GameSystems::playerEntity != nullptr)
    {
        bool collisionDetected = SDL_HasIntersection(&collisionBox, &GameSystems::playerEntity->GetCollisionBox());
        if(collisionDetected) 
        { 
            notify(testEntity, std::make_shared<CollisionEvent>(*GameSystems::playerEntity, collisionType, CollisionEnum::collisionPlayer)); 
        }
    }
}
