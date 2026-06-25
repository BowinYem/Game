#include "CollisionComponent.h"
#include "GameEntity.h"
#include "GameSystems.h"
#include "CollisionSystem.h"
#include "CollisionEvent.h"
#include "EntityPool.h"

CollisionComponent::CollisionComponent(const SDL_Rect& collisionBox_, CollisionEnum collisionType_) : collisionBox{collisionBox_}, collisionType{collisionType_} 
{ 
    addSystem(GameSystems::collisionSys);
}

void CollisionComponent::update(GameEntity& entity)
{
    updateCollisionBox(entity);
    detectCollisions(entity);
}

void CollisionComponent::removeSystem(const std::shared_ptr<System> sys)
{
    for(auto i = systemList.begin(); i < systemList.end(); ++i)
    {
        if(*i == sys)
            { systemList.erase(i); }
    }
}

void CollisionComponent::updateCollisionBox(const GameEntity& entity)
{
    collisionBox.x = entity.physicsState.currPosition.x;
    collisionBox.y = entity.physicsState.currPosition.y;
}

void CollisionComponent::notify(GameEntity& entity, const std::shared_ptr<Event> const event)
{
    for(auto& sys : systemList)
    {
        sys->onNotify(entity, event);
    }
}

