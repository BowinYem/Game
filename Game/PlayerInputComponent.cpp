#include "PlayerInputComponent.h"
#include "GameSystems.h"
#include "InputSystem.h"

void PlayerInputComponent::Update(GameEntity& entity)
{
    auto inputSys = GameSystems::inputSys->GetInstance();

    // Rotation
    if (inputSys->GetActionState(GameGlobals::ActionEnumType::ActionRotateLeft))
    {
        entity.rotateDir = RotateDirection::rotateLeft;
    }
    else if (inputSys->GetActionState(GameGlobals::ActionEnumType::ActionRotateRight))
    {
       entity.rotateDir = RotateDirection::rotateRight;
    }
    else
    {
        entity.rotateDir = RotateDirection::rotateNone;
    }

    // Forward Movement
    if (inputSys->GetActionState(GameGlobals::ActionEnumType::ActionMoveForward))
    {
        entity.moveDirX = MovementDirection::movementForward;
        entity.moveDirY = MovementDirection::movementForward;
    }
    else if (inputSys->GetActionState(GameGlobals::ActionEnumType::ActionMoveBack))
    {
        entity.moveDirX = MovementDirection::movementBackwards;
        entity.moveDirY = MovementDirection::movementBackwards;
    }
    else
    {
        entity.moveDirX = MovementDirection::movementNone;
        entity.moveDirY = MovementDirection::movementNone;
    }

    // // Actions
    if(inputSys->GetActionState(GameGlobals::ActionEnumType::ActionShoot))
    {
        GameSystems::projectilePool->Create(entity.renderPosition, entity.renderRotation);
    }
}







