#pragma once
#include <stdint.h>
#include <array>
#include "GameEntity.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"
#include "GameVector.h"

template <typename EntityType>
class EntityPool
{
public:
    EntityPool(size_t poolSize) : entities(poolSize), entitiesInUse(poolSize) { /*...*/}

    bool Create(const GameVector& position, int16_t rotation)
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

                entities[i].moveDirX = MovementDirection::movementNone;
                entities[i].moveDirY = MovementDirection::movementNone;
                entities[i].rotateDir = RotateDirection::rotateNone;
                entitiesInUse[i] = true;
                ++activeEntities;
                entityCreated = true;
                break;
            }
        }

        return entityCreated;
    }

    bool Destroy(uint8_t index)
    {
        if((entitiesInUse[index]) && (activeEntities > 0))
        {
            entities[index].renderPosition = {0, 0};
            entities[index].physicsState.currPosition = {0, 0};
            entities[index].physicsState.prevPosition = {0, 0};

            entities[index].renderRotation = 0; 
            entities[index].physicsState.currRotation = 0;
            entities[index].physicsState.prevRotation = 0;

            entities[index].moveDirX = MovementDirection::movementNone;
            entities[index].moveDirY = MovementDirection::movementNone;
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

    inline bool IsEntityInUse(uint8_t index) { return entitiesInUse[index]; }

    void UpdatePhysics(double extrapolateVal)
    {
        for(uint8_t i = 0; i < entities.size(); ++i)
        {       
            if(entitiesInUse[i]) { entities[i].UpdatePhysics(extrapolateVal); }
        }
    }

    void UpdateInput()
    {
        for(uint8_t i = 0; i < entities.size(); ++i)
        {       
            if(entitiesInUse[i]) { entities[i].UpdateInput(); }
        }       
    }

    void UpdateSprite(double alpha)
    {
        for(uint8_t i = 0; i < entities.size(); ++i)
        {       
            if(entitiesInUse[i]) { entities[i].UpdateSprite(alpha); }
        }       
    }

    void UpdateCollision()
    {
        for(uint8_t i = 0; i < entities.size(); ++i)
        {       
            if(entitiesInUse[i]) { entities[i].UpdateCollision(); }
        }
    }   

    inline EntityType& GetEntity(uint8_t index) { return entities[index]; }

    inline uint8_t GetTotalActiveEntities() { return activeEntities; }; 

    inline uint16_t GetPoolSize() { return entities.size(); }

private:
    uint8_t activeEntities = 0;
    std::vector<EntityType> entities;
    std::vector<bool> entitiesInUse; 
};

