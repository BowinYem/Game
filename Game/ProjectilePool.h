#pragma once
#include <stdint.h>
#include <array>
#include "GameEntity.h"
#include "SpriteComponent.h"
#include "GameVector.h"

constexpr uint8_t ProjectilePoolSize = 25;

class ProjectilePool
{
public:
    ProjectilePool();
    void Create(const GameVector& position_, int16_t rotation_);
    void Destroy(uint8_t index);
    void Update();
    inline bool IsProjectileInUse(uint8_t index) { return projectileInUse[index]; }
    GameEntity& GetProjectile(uint8_t index);

private:
    SpriteComponent projectileSprite;
    std::array<GameEntity, ProjectilePoolSize> projectiles;
    std::array<bool, ProjectilePoolSize> projectileInUse; 
};