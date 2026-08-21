#pragma once
#include "CollisionComponent.h"
#include "GameEntity.h"
#include "GameRect.h"

class EnemyCollisionComponent : public CollisionComponent
{
public:
    EnemyCollisionComponent(const GameRect& collisionBox_);
    void DetectCollisions(GameEntity& entity) override;

};