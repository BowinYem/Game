#pragma once
#include "SDL.h"
#include "System.h"
#include "Event.h"
#include "CollisionEvent.h"
#include "CollisionEnum.h"
#include <vector>
#include <memory>

class GameEntity;
class System;

class CollisionComponent
{
 public:
    CollisionComponent(const SDL_Rect& collisionBox_, CollisionEnum collisionType_ = CollisionEnum::collisionNone);
    virtual void update(GameEntity& entity);
    inline void addSystem(const std::shared_ptr<System> sys) { systemList.push_back(sys); };
    void removeSystem(const std::shared_ptr<System> sys);

protected:
    void notify(GameEntity& entity, const std::shared_ptr<Event> const event);

 private:
    virtual void detectCollisions(GameEntity& entity) = 0;
    virtual void updateCollisionBox(const GameEntity& entity);

 public:
    SDL_Rect collisionBox;

 private:
    std::vector<std::shared_ptr<System>> systemList;
    
 protected:
    CollisionEnum collisionType;
};