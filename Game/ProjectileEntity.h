#pragma once
#include "GameEntity.h"
#include "CollisionSystem.h"

class ProjectileEntity : public GameEntity
{
friend CollisionSystem;

public:
    ProjectileEntity();

protected:
    bool ProjectileDespawnCheck();
};