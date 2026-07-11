#pragma once
#include "System.h"
#include "CollisionEvent.h"

class CollisionSystem : public System
{
public:
    void onNotify(GameEntity& entity, const std::shared_ptr<Event> const e) override;
private:
    void handlePlayerCollision(GameEntity& playerEntity, const std::shared_ptr<CollisionEvent> const e);
    void handleProjectileCollision(GameEntity& projectileEntity, const std::shared_ptr<CollisionEvent> const e);
    void handleEnemyCollision(GameEntity& enemyEntity, const std::shared_ptr<CollisionEvent> const e);


};
