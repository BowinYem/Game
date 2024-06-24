#include "ProjectilePool.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"

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
            projectiles[i].xVelocity = 5;
            projectiles[i].yVelocity = 5;
            projectileInUse[i] = true;
            break;
        }
    }
}

void ProjectilePool::Destroy(uint8_t index)
{
    projectiles[index].position = {0, 0};
    projectiles[index].rotation = 0; 
    projectiles[index].xVelocity = 0;
    projectiles[index].yVelocity = 0;
    projectiles[index].rotationVelocity = 0;
    projectileInUse[index] = false;
}

void ProjectilePool::Update()
{
    for(uint8_t i = 0; i < ProjectilePoolSize; ++i)
    {
        if(projectiles[i].position.x > 500)
            { Destroy(i); }        
        else if(projectileInUse[i]) 
            { projectiles[i].Update(); }
    }
}

const GameEntity& ProjectilePool::GetProjectile(uint8_t index) 
{
    if(projectileInUse[index])
        { return projectiles[index]; }
}