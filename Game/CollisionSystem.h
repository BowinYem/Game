#pragma once
#include "System.h"
#include "CollisionEvent.h"
#include "GameEntity.h"
#include <memory>

class CollisionSystem : public System
{
public:
    void OnNotify(GameEntity& entity, const std::shared_ptr<const Event> e) override;

private:
    void HandlePlayerCollision(GameEntity& playerEntity, const std::shared_ptr<const CollisionEvent> e);
    void HandleProjectileCollision(GameEntity& projectileEntity, const std::shared_ptr<const CollisionEvent> e);
    void HandleEnemyCollision(GameEntity& enemyEntity, const std::shared_ptr<const CollisionEvent> e);
    void BoundaryBlock(GameEntity& entity);
};
