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
        currMeteor.SetSpriteComponent(std::make_shared<SpriteComponent>(meteorSprite));
        SDL_Rect CollisionBoxSize;
        CollisionBoxSize.h = MeteorHeight;
        CollisionBoxSize.w = MeteorWidth;
        currMeteor.SetPhysicsComponent(std::make_shared<PhysicsComponent>(CollisionBoxSize));
        currMeteor.entityType = EntityType::MeteorEntity;
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
            meteors[i].xVelocity = -1;
            meteors[i].yVelocity = -1;
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
        if(meteorInUse[i])
        {
            meteors[i].Update(); 
        }
    }
}