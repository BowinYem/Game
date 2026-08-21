#include "EnemyCollisionComponent.h"
#include "GameSystems.h"

EnemyCollisionComponent::EnemyCollisionComponent(const GameRect& collisionBox_) : CollisionComponent{CollisionEnum::collisionEnemy, collisionBox_} 
{  
    //...
}

void EnemyCollisionComponent::DetectCollisions(GameEntity& entity)
{
    CollisionComponent::DetectCollisions(entity);

    if(GameSystems::playerEntity != nullptr)
    {
        bool collisionDetected = GameRect::HasIntersection(collisionBox, GameSystems::playerEntity->GetCollisionBox());
        if(collisionDetected) 
        { 
            Notify(entity, std::make_shared<CollisionEvent>(*GameSystems::playerEntity, collisionType, CollisionEnum::collisionPlayer)); 
        }
    }
}
