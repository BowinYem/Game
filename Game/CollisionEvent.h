#pragma once
#include "Event.h"
#include "GameEntity.h"
#include "CollisionEnum.h"


class CollisionEvent : public Event
{
public:
    CollisionEvent(GameEntity& otherEntity, CollisionEnum senderType_, CollisionEnum otherType_);
    GameEntity& collidedEntity;
    CollisionEnum senderType;
    CollisionEnum otherType;
};