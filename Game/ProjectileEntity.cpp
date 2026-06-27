#include "ProjectileEntity.h"
#include "SpriteComponent.h"
#include "ProjectileInputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "ProjectileCollisionComponent.h"

//temporary - will be removed later
constexpr SDL_Rect projCollisionBox = {0, 0, 50, 50};

ProjectileEntity::ProjectileEntity() : GameEntity(std::make_shared<SpriteComponent>("star.bmp"), std::make_shared<ProjectileInputComponent>(),  
    std::make_shared<PlayerPhysicsComponent>(), std::make_shared<ProjectileCollisionComponent>(projCollisionBox))
{
    //...
}