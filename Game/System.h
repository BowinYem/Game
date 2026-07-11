#pragma once
#include "GameEntity.h"
#include "Event.h"
#include <memory>

class System
{
 public:
    virtual void onNotify(GameEntity& entity, const std::shared_ptr<Event> const e) = 0;
};