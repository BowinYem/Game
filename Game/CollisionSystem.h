#pragma once
#include "System.h"
#include "CollisionEvent.h"

class CollisionSystem : public System
{
public:
    void onNotify(const GameEntity& entity,  const std::shared_ptr<Event> const e) override;
private:
    void handlePlayerCollision(const GameEntity& playerEntity, const std::shared_ptr<CollisionEvent> const e);
    void handleProjectileCollision(const GameEntity& projectileEntity, const std::shared_ptr<CollisionEvent> const e);
    void handleEnemyCollision(const GameEntity& enemyEntity, const std::shared_ptr<CollisionEvent> const e);


};
