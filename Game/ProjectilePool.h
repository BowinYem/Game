#pragma once
#include <stdint.h>
#include <vector>
#include "GameEntity.h"

class ProjectilePool
{
public:
    ProjectilePool();

private:
    std::vector<GameEntity> projectiles;
};