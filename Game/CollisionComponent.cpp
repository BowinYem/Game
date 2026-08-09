#include "CollisionComponent.h"
#include "GameSystems.h"

CollisionComponent::CollisionComponent(const CollisionEnum& collisionType_, const GameRect& collisionBox_) 
    : collisionType{collisionType_}, collisionBox{collisionBox_}
{ 
    AddSystem(GameSystems::collisionSys);
}

void CollisionComponent::Update(GameEntity& entity)
{
    UpdateCollisionBox(entity);
    DetectCollisions(entity);
}

void CollisionComponent::RemoveSystem(const std::shared_ptr<System> sys)
{
    for(auto i = systemList.begin(); i < systemList.end(); ++i)
    {
        if(*i == sys)
            { systemList.erase(i); }
    }
}

void CollisionComponent::UpdateCollisionBox(const GameEntity& entity)
{
    collisionBox.x = entity.physicsState.currPosition.x;
    collisionBox.y = entity.physicsState.currPosition.y;
}

void CollisionComponent::Notify(GameEntity& entity, const std::shared_ptr<const Event> event)
{
    for(auto& sys : systemList)
    {
        sys->OnNotify(entity, event);
    }
}

