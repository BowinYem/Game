#pragma once
#include "Event.h"
#include "GameEntity.h"
#include "CollisionEnum.h"


class CollisionEvent : public Event
{
public:
    CollisionEvent(GameEntity& collidedEntity_, const CollisionEnum& senderType_, const CollisionEnum& otherType_);

    GameEntity& collidedEntity;
    CollisionEnum senderType;
    CollisionEnum otherType;
};