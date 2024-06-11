#include "ProjectilePool.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"

//static SpriteComponent projectileSpriteComp{"star.bmp"};

ProjectilePool::ProjectilePool() : projectileSprite { "star.bmp" }
{
    for(GameEntity& currProjectile : projectiles)
    {
        currProjectile.SetSpriteComponent(std::unique_ptr<SpriteComponent>{&projectileSprite});
        currProjectile.SetPhysicsComponent(std::make_unique<PhysicsComponent>());
    }
}

void ProjectilePool::Animate()
{
    for(GameEntity& currProjectile : projectiles)
    {
        currProjectile.Update();
    }
}