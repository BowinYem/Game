#include "EnemyEntity.h"
#include "EnemyInputComponent.h"
#include "RotatePhysicsComponent.h"
#include "EnemyCollisionComponent.h"
#include "GameSystems.h"

EnemyEntity::EnemyEntity() : GameEntity(
    std::make_shared<SpriteComponent>(std::string(GameGlobals::enemySpriteFile)), 
    std::make_shared<EnemyInputComponent>(),  
    std::make_shared<RotatePhysicsComponent>(GameGlobals::EnemyVelocity, GameGlobals::EnemyVelocity, GameGlobals::EnemyRotateVelocity), 
    std::make_shared<EnemyCollisionComponent>(GameGlobals::enemyCollisionBox))
{
    //...
}