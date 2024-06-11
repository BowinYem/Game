#pragma once
#include <stdint.h>
#include <array>
#include "GameEntity.h"
#include "SpriteComponent.h"
#include "GameVector.h"

constexpr uint8_t ProjectilePoolSize = 50;

class SpriteComponent;

class ProjectilePool
{
public:
    ProjectilePool();
    void Create(const GameVector& position_, int16_t rotation_);
    void Update();

private:
    SpriteComponent projectileSprite;
    std::array<GameEntity, ProjectilePoolSize> projectiles;
    std::array<bool, ProjectilePoolSize> projectileInUse; 
};