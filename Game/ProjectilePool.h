#pragma once
#include <stdint.h>
#include <array>

constexpr uint8_t ProjectilePoolSize = 50;

// Forward declarations
class Projectile;

class ProjectilePool
{
public:
    ProjectilePool();

private:
    std::array<Projectile, ProjectilePoolSize> projectles;
};