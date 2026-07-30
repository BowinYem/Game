#include "EnemyCollisionComponent.h"
#include "GameSystems.h"

EnemyCollisionComponent::EnemyCollisionComponent(const GameRect& collisionBox_) : CollisionComponent{collisionBox_, CollisionEnum::collisionEnemy} 
{  
    //...
}

void EnemyCollisionComponent::DetectCollisions(GameEntity& testEntity)
{
    if(GameSystems::playerEntity != nullptr)
    {
        bool collisionDetected = GameRect::HasIntersection(collisionBox, GameSystems::playerEntity->GetCollisionBox());
        if(collisionDetected) 
        { 
            Notify(testEntity, std::make_shared<CollisionEvent>(*GameSystems::playerEntity, collisionType, CollisionEnum::collisionPlayer)); 
        }
    }
}
