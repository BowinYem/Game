#pragma once
#include <stdint.h>
#include <array>
#include "GameEntity.h"
#include "SpriteComponent.h"
#include "GameVector.h"

constexpr uint8_t MeteorPoolSize = 25;
constexpr uint16_t MeteorHeight = 50;
constexpr uint16_t MeteorWidth = 50; 

class MeteorPool
{
public:
    MeteorPool();
    bool Create(const GameVector& position_, int16_t rotation_);
    bool Destroy(uint8_t index);
    inline bool IsMeteorInUse(uint8_t index) { return meteorInUse[index]; }
    void Update();
    inline GameEntity& GetMeteor(uint8_t index) { return meteors[index]; }
    inline uint8_t GetTotalActiveMeteors() { return activeMeteors; }; 


private:
    uint8_t activeMeteors = 0;
    SpriteComponent meteorSprite;
    std::array<GameEntity, MeteorPoolSize> meteors;
    std::array<bool, MeteorPoolSize> meteorInUse; 
};