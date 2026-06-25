#include "CollisionEvent.h"

CollisionEvent::CollisionEvent(GameEntity& otherEntity,  CollisionEnum senderType_, CollisionEnum otherType_) : 
    Event{EventType::CollisionEvent}, collidedEntity{otherEntity}, senderType{senderType_}, otherType{otherType_}
{
    //...
}
