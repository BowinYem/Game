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

void CollisionComponent::Notify(GameEntity& entity, const std::shared_ptr<const Event> event)
{
    for(auto& sys : systemList)
    {
        sys->OnNotify(entity, event);
    }
}

void CollisionComponent::DetectCollisions(GameEntity& entity)
{
    // Check to see if entity is making countary with the level boundary
    if((collisionBox.x < 0) || (collisionBox.x > (GameGlobals::GameLevelWidth - collisionBox.w)) ||
        (collisionBox.y < 0) || (collisionBox.y > (GameGlobals::GameLevelHeight - collisionBox.h)))
    {
        Notify(entity, std::make_shared<CollisionEvent>(entity, collisionType, CollisionEnum::collisionBoundary)); 
    }
}

void CollisionComponent::UpdateCollisionBox(const GameEntity& entity)
{
    collisionBox.x = entity.physicsState.currPosition.x;
    collisionBox.y = entity.physicsState.currPosition.y;
}