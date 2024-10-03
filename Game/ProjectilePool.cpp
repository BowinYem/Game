#include "ProjectilePool.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"
#include "GameSystems.h"

#include "GameRenderer.h" //TODO: Delete this

ProjectilePool::ProjectilePool() : projectileSprite { "star.bmp" }
{
    for(GameEntity& currProjectile : projectiles)
    {
        currProjectile.SetSpriteComponent(std::make_shared<SpriteComponent>(projectileSprite));
        SDL_Rect CollisionBoxSize;
        CollisionBoxSize.h = ProjectileHeight;
        CollisionBoxSize.w = ProjectileWidth;
        currProjectile.SetPhysicsComponent(std::make_shared<PhysicsComponent>(CollisionBoxSize));
    }
}

bool ProjectilePool::Create(const GameVector& position_, int16_t rotation_)
{
    bool projectileCreated = false;

    for(uint16_t i = 0; i < ProjectilePoolSize; ++i)
    {
        if(!projectileInUse[i])
        {
            projectiles[i].position = position_;
            projectiles[i].rotation = rotation_;
            projectiles[i].xVelocity = 3;
            projectiles[i].yVelocity = 3;
            projectileInUse[i] = true;
            
            ++activeProjectiles;
            projectileCreated = true;
            break;
        }
    }
    
    return projectileCreated;
}

bool ProjectilePool::Destroy(uint8_t index)
{
    if((projectileInUse[index]) && (activeProjectiles > 0))
    {
        projectiles[index].position = {0, 0};
        projectiles[index].rotation = 0; 
        projectiles[index].xVelocity = 0;
        projectiles[index].yVelocity = 0;
        projectiles[index].rotationVelocity = 0;
        projectileInUse[index] = false;
        
        --activeProjectiles;
        return true;
    }
    else 
    {
        return false;
    }
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

