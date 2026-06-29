#include "EnemyEntity.h"
#include "EnemyInputComponent.h"
#include "RotatePhysicsComponent.h"
#include "EnemyCollisionComponent.h"

//temporary - will be removed later
constexpr SDL_Rect enemyCollisionBox = {0, 0, 50, 50};

EnemyEntity::EnemyEntity() : GameEntity(std::make_shared<SpriteComponent>("star.bmp"), std::make_shared<EnemyInputComponent>(),  
    std::make_shared<RotatePhysicsComponent>(), std::make_shared<EnemyCollisionComponent>(enemyCollisionBox))
{
    //...
}