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
            projectiles[i].xVelocity = 5;
            projectiles[i].yVelocity = 5;
            projectileInUse[i] = true;
            break;
        }
    }
}

void ProjectilePool::Update()
{
    for(uint8_t i = 0; i < ProjectilePoolSize; ++i)
    {
        //"Destroy" invalid projeciles - subject to change. Make this it's own seperate function
        if(projectiles[i].position.x > 500)
        {
            projectiles[i].position = {0, 0};
            projectiles[i].rotation = 0; 
            projectiles[i].xVelocity = 0;
            projectiles[i].yVelocity = 0;
            projectiles[i].rotationVelocity = 0;
            projectileInUse[i] = false;
        }       

        if(projectileInUse[i]) 
            { projectiles[i].Update(); }
    }
}