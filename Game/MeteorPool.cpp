#include "MeteorPool.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"
#include "GameSystems.h"
#include "ProjectilePool.h"

#include <iostream> // TODO: delete
#include "GameRenderer.h" // TODO: delete 

MeteorPool::MeteorPool() : meteorSprite { "star.bmp" }
{
    for(GameEntity& currMeteor : meteors)
    {
        currMeteor.SetSpriteComponent("star.bmp");
        SDL_Rect CollisionBoxSize;
        CollisionBoxSize.h = 50;
        CollisionBoxSize.w = 50;
        currMeteor.SetPhysicsComponent(std::make_unique<PhysicsComponent>(CollisionBoxSize));
    }
}

void MeteorPool::Create(const GameVector& position_, int16_t rotation_)
{
    for(uint16_t i = 0; i < MeteorPoolSize; ++i)
    {
        if(!meteorInUse[i])
        {
            meteors[i].position = position_;
            meteors[i].rotation = rotation_;
            meteors[i].xVelocity = -3;
            meteors[i].yVelocity = -3;
            meteorInUse[i] = true;
            break;
        }
    }
}

void MeteorPool::Destroy(uint8_t index)
{
    meteors[index].position = {0, 0};
    meteors[index].rotation = 0; 
    meteors[index].xVelocity = 0;
    meteors[index].yVelocity = 0;
    meteors[index].rotationVelocity = 0;
    meteorInUse[index] = false;
}

void MeteorPool::Update()
{
    for(uint8_t i = 0; i < MeteorPoolSize; ++i)
    {
        for(uint8_t j = 0; j < ProjectilePoolSize; ++j)
        {
            if(meteorInUse[i] && GameSystems::projectilePool->IsProjectileInUse(j))
            {  
                auto& projectile = GameSystems::projectilePool->GetProjectile(j);
                bool collided = SDL_HasIntersection(&meteors[i].GetCollisionBox(), &projectile.GetCollisionBox());

                if (collided)
                {
                    std::cout << "Collision" << std::endl;
                    Destroy(i);
                }
            }
        }
        
        if(meteorInUse[i])
        {
            meteors[i].Update(); 
        }
    }
}