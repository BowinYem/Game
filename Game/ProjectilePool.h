#pragma once
#include <stdint.h>
#include <array>
#include "GameEntity.h"
#include "SpriteComponent.h"

constexpr uint8_t ProjectilePoolSize = 50;

class SpriteComponent;

class ProjectilePool
{
public:
    ProjectilePool();
    void Animate();

private:
    SpriteComponent projectileSprite;
    std::array<GameEntity, ProjectilePoolSize> projectiles;
};