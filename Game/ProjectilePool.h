#pragma once
#include <stdint.h>
#include <array>
#include "GameEntity.h"
#include "SpriteComponent.h"
#include "GameVector.h"

constexpr uint8_t ProjectilePoolSize = 5;
constexpr uint16_t ProjectileHeight = 50;
constexpr uint16_t ProjectileWidth = 50; 

class ProjectilePool
{
public:
    ProjectilePool();
    bool Create(const GameVector& position_, int16_t rotation_);
    bool Destroy(uint8_t index);
    void Update(double extrapolateVal);
    void UpdatePhysics(double extrapolateVal);
    void UpdateInput();
    void UpdateSprite();
    inline bool IsProjectileInUse(uint8_t index) { return projectileInUse[index]; }
    GameEntity& GetProjectile(uint8_t index);
    inline uint8_t GetTotalActiveProjectiles() { return activeProjectiles; }; 

private:
    uint8_t activeProjectiles = 0;
    SpriteComponent projectileSprite;
    std::array<GameEntity, ProjectilePoolSize> projectiles;
    std::array<bool, ProjectilePoolSize> projectileInUse; 
};