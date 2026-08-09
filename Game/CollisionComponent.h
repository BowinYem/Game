#pragma once
#include "SDL.h"
#include "System.h"
#include "Event.h"
#include "CollisionEvent.h"
#include "CollisionEnum.h"
#include "GameEntity.h"
#include "GameRect.h"
#include <vector>
#include <memory>

// Forward Declarations
class GameEntity;
class System;

class CollisionComponent
{
public:
   CollisionComponent(const CollisionEnum& collisionType_ = CollisionEnum::collisionNone, const GameRect& collisionBox_ = {0.0f, 0.0f, 0.0f, 0.0f});
   virtual void Update(GameEntity& entity);
   inline void AddSystem(const std::shared_ptr<System> sys) { systemList.push_back(sys); };
   void RemoveSystem(const std::shared_ptr<System> sys);

   GameRect collisionBox;

protected:
   void Notify(GameEntity& entity, const std::shared_ptr<const Event> event);

   CollisionEnum collisionType;

private:
   virtual void DetectCollisions(GameEntity& entity) = 0;
   virtual void UpdateCollisionBox(const GameEntity& entity);

   std::vector<std::shared_ptr<System>> systemList;
};