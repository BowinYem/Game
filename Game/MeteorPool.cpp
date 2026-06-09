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
    }
}

bool MeteorPool::Create(const GameVector& position_, int16_t rotation_)
{
    bool meteorCreated = false;

    for(uint16_t i = 0; i < MeteorPoolSize; ++i)
    {
        if(!meteorInUse[i])
        {
            meteors[i].renderPosition = position_;
            meteors[i].renderRotation = rotation_;
            meteors[i].moveDir = MovementDirection::movementBackwards;
            meteorInUse[i] = true;
            ++activeMeteors;
            meteorCreated = true;
            break;
        }
    }

    return meteorCreated;
}

bool MeteorPool::Destroy(uint8_t index)
{
    if((meteorInUse[index]) && (activeMeteors > 0))
    {
        meteors[index].renderPosition = {0, 0};
        meteors[index].renderRotation = 0; 
        meteors[index].moveDir = MovementDirection::movementNone;
        meteors[index].rotateDir = RotateDirection::rotateNone;
        meteorInUse[index] = false;
        --activeMeteors;
        return true;
    }
    else
    {
        return false;
    }
}

void MeteorPool::Update(double extrapolateVal)
{
    for(uint8_t i = 0; i < MeteorPoolSize; ++i)
    {       
        if(meteorInUse[i]) { meteors[i].Update(extrapolateVal); }
    }
}

void MeteorPool::UpdatePhysics(double extrapolateVal)
{
    for(uint8_t i = 0; i < MeteorPoolSize; ++i)
    {       
        if(meteorInUse[i]) { meteors[i].UpdatePhysics(extrapolateVal); }
    }
}

void MeteorPool::UpdateInput()
{
    for(uint8_t i = 0; i < MeteorPoolSize; ++i)
    {       
        if(meteorInUse[i]) { meteors[i].UpdateInput(); }
    }
}

void MeteorPool::UpdateSprite(double alpha)
{
    for(uint8_t i = 0; i < MeteorPoolSize; ++i)
    {       
        if(meteorInUse[i]) { meteors[i].UpdateSprite(alpha); }
    }
}