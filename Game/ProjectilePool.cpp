#include "ProjectilePool.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"
#include "GameSystems.h"

#include "GameRenderer.h" //TODO: Delete this

ProjectilePool::ProjectilePool() : projectileSprite { "star.bmp" }
{
    for(GameEntity& currProjectile : projectiles)
    {
        currProjectile.SetSpriteComponent("star.bmp");
        SDL_Rect CollisionBoxSize;
        CollisionBoxSize.h = 50;
        CollisionBoxSize.w = 50;
        currProjectile.SetPhysicsComponent(std::make_unique<PhysicsComponent>(CollisionBoxSize));
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
            projectiles[i].xVelocity = 3;
            projectiles[i].yVelocity = 3;
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
        if(projectileInUse[i]) 
        { 
            projectiles[i].Update(); 
        }
    }
}

GameEntity& ProjectilePool::GetProjectile(uint8_t index) 
{
    return projectiles[index]; 
}