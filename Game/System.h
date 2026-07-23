#pragma once
#include "GameEntity.h"
#include "Event.h"
#include <memory>

class System
{
 public:   
    
    virtual void OnNotify(GameEntity& entity, const std::shared_ptr<const Event> e) = 0;
};