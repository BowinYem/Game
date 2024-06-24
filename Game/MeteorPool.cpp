#include "MeteorPool.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"

MeteorPool::MeteorPool() : meteorSprite { "star.bmp" }
{
    for(GameEntity& currMeteor : meteors)
    {
        currMeteor.SetSpriteComponent(std::unique_ptr<SpriteComponent>{&meteorSprite});
        currMeteor.SetPhysicsComponent(std::make_unique<PhysicsComponent>());
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
            meteors[i].xVelocity = 5;
            meteors[i].yVelocity = 5;
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
        if(meteors[i].position.x > 500)
            { Destroy(i); }        
        else if(meteorInUse[i]) 
            { meteors[i].Update(); }
    }
}