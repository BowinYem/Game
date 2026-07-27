#include "ProjectileEntity.h"
#include "SpriteComponent.h"
#include "ProjectileInputComponent.h"
#include "RotatePhysicsComponent.h"
#include "ProjectileCollisionComponent.h"
#include "GameSystems.h"

ProjectileEntity::ProjectileEntity() : GameEntity(
    std::make_shared<SpriteComponent>(std::string(GameGlobals::ProjectileSpriteFile)), 
    std::make_shared<ProjectileInputComponent>(),  
    std::make_shared<RotatePhysicsComponent>(GameGlobals::ProjectileVelocity, GameGlobals::ProjectileVelocity, GameGlobals::ProjectileRotateVelocity), 
    std::make_shared<ProjectileCollisionComponent>(GameGlobals::ProjectileCollisionBox))
{
    //...
}