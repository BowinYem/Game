#include "TestInputComponent.h"
#include "GameSystems.h"

void TestInputComponent::Update(GameEntity& entity)
{
    entity.moveDirX = MovementDirection::movementForward;
    entity.moveDirY = MovementDirection::movementForward;
}