#pragma once
#include <stdint.h>
#include <array>
#include "GameEntity.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"
#include "GameVector.h"

class EntityPool
{
public:
    EntityPool(size_t poolSize);
    bool Create(const GameVector& position_, int16_t rotation_);
    bool Destroy(uint8_t index);
    inline bool IsEntityInUse(uint8_t index) { return entitiesInUse[index]; }
    void Update(double extrapolateVal);
    void UpdatePhysics(double extrapolateVal);
    void UpdateInput();
    void UpdateSprite(double alpha);
    void UpdateCollision(); 
    inline GameEntity& GetEntity(uint8_t index) { return entities[index]; }
    inline uint8_t GetTotalActiveEntities() { return activeEntities; }; 
    inline uint16_t GetPoolSize() { return entities.size(); }

private:
    uint8_t activeEntities = 0;
    SpriteComponent entitySprite;
    std::vector<GameEntity> entities;
    std::vector<bool> entitiesInUse; 
};