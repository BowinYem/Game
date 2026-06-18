#include "EntityPool.h"
#include "TestInputComponent.h"
#include "PlayerPhysicsComponent.h"

constexpr uint16_t SpriteHeight = 50;
constexpr uint16_t SpriteWidth = 50; 

// TO DO!!!!!!!!!!!!! Look into giving SpriteComponent an implicit default constructor
EntityPool::EntityPool(size_t poolSize) : entities(poolSize), entitiesInUse(poolSize), entitySprite("star.bmp")
{
    for(GameEntity& currEntity : entities)
    {
        currEntity.SetSpriteComponent(std::make_shared<SpriteComponent>(entitySprite));
        SDL_Rect CollisionBoxSize;
        CollisionBoxSize.h = SpriteHeight;
        CollisionBoxSize.w = SpriteWidth;

        // Probably going to change/remove
        currEntity.SetInputComponent(std::make_shared<TestInputComponent>());
        currEntity.SetPhysicsComponent(std::make_shared<PlayerPhysicsComponent>(CollisionBoxSize)); 
    }    
}

bool EntityPool::Create(const GameVector& position, int16_t rotation)
{
    bool entityCreated = false;

    for(uint16_t i = 0; i < entities.size(); ++i)
    {
        if(!entitiesInUse[i])
        {
            entities[i].renderPosition = position;
            entities[i].physicsState.currPosition = position;
            entities[i].physicsState.prevPosition = position;
            
            entities[i].renderRotation = rotation;
            entities[i].physicsState.currRotation = rotation;
            entities[i].physicsState.prevRotation = rotation;

            entities[i].moveDir = MovementDirection::movementNone;
            entities[i].rotateDir = RotateDirection::rotateNone;
            entitiesInUse[i] = true;
            ++activeEntities;
            entityCreated = true;
            break;
        }
    }

    return entityCreated;
}

bool EntityPool::Destroy(uint8_t index)
{
    if((entitiesInUse[index]) && (activeEntities > 0))
    {
        entities[index].renderPosition = {0, 0};
        entities[index].physicsState.currPosition = {0, 0};
        entities[index].physicsState.prevPosition = {0, 0};

        entities[index].renderRotation = 0; 
        entities[index].physicsState.currRotation = 0;
        entities[index].physicsState.prevRotation = 0;

        entities[index].moveDir = MovementDirection::movementNone;
        entities[index].rotateDir = RotateDirection::rotateNone;
        entitiesInUse[index] = false;
        --activeEntities;
        return true;
    }
    else
    {
        return false;
    }
}

// No physics component yet
void EntityPool::UpdatePhysics(double extrapolateVal)
{
    for(uint8_t i = 0; i < entities.size(); ++i)
    {       
        if(entitiesInUse[i]) { entities[i].UpdatePhysics(extrapolateVal); }
    }
}

// No input component yet
void EntityPool::UpdateInput()
{
    for(uint8_t i = 0; i < entities.size(); ++i)
    {       
        if(entitiesInUse[i]) { entities[i].UpdateInput(); }
    }
}

void EntityPool::UpdateSprite(double alpha)
{
    for(uint8_t i = 0; i < entities.size(); ++i)
    {       
        if(entitiesInUse[i]) { entities[i].UpdateSprite(alpha); }
    }
}