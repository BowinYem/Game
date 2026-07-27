#include "ProjectileInputComponent.h"

void ProjectileInputComponent::Update(GameEntity& entity)
{
    if((entity.moveDirX != MovementDirection::movementForward) && 
        (entity.moveDirY != MovementDirection::movementForward))
    { 
        entity.moveDirX = MovementDirection::movementForward;
        entity.moveDirY = MovementDirection::movementForward; 
    }
}

