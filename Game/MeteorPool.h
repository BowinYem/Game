#pragma once
#include <stdint.h>
#include <array>
#include "GameEntity.h"
#include "SpriteComponent.h"
#include "GameVector.h"

constexpr uint8_t MeteorPoolSize = 1;

class MeteorPool
{
public:
    MeteorPool();
    void Create(const GameVector& position_, int16_t rotation_);
    void Destroy(uint8_t index);
    void Update();

private:
    SpriteComponent meteorSprite;
    std::array<GameEntity, MeteorPoolSize> meteors;
    std::array<bool, MeteorPoolSize> meteorInUse; 
};