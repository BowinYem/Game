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

void ProjectilePool::Create(const GameVector& position_, int16_t rotation_)
{
    for(uint16_t i = 0; i < ProjectilePoolSize; ++i)
    {
        if(!projectileInUse[i])
        {
            projectiles[i].position = position_;
            projectiles[i].rotation = rotation_;
        }
    }
}

void ProjectilePool::Update()
{
    for(GameEntity& currProjectile : projectiles)
    {
        currProjectile.Update();
    }
}