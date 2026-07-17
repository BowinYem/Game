#include "CollisionEvent.h"

CollisionEvent::CollisionEvent(GameEntity& collidedEntity_, const CollisionEnum& senderType_, const CollisionEnum& otherType_) : 
    Event{EventType::CollisionEvent}, collidedEntity{collidedEntity_}, senderType{senderType_}, otherType{otherType_}
{
    //...
}
