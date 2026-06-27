#include "ProjectileInputComponent.h"
#include "GameEntity.h"

void ProjectileInputComponent::Update(GameEntity& entity)
{
    if(entity.moveDir != MovementDirection::movementForward)
        { entity.moveDir = MovementDirection::movementForward; }
}

