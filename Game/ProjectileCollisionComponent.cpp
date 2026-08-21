#include "ProjectileCollisionComponent.h"
#include "GameSystems.h"

ProjectileCollisionComponent::ProjectileCollisionComponent(const GameRect& collisionBox_) : CollisionComponent{CollisionEnum::collisionProjectile, collisionBox_}
{  
    //...
}

void ProjectileCollisionComponent::DetectCollisions(GameEntity& entity)
{
    CollisionComponent::DetectCollisions(entity);

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
}
