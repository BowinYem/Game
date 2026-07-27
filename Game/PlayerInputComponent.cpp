#include "PlayerInputComponent.h"
#include "GameSystems.h"
#include <stdint.h>

void PlayerInputComponent::Update(GameEntity& entity)
{
    // Do basic input handling here for now
    const uint8_t* keyboardState = GameSystems::keyboardState;
    SDL_Keycode actionEvent = GameSystems::actionEvent;

    // Rotation
    if (keyboardState[SDL_SCANCODE_LEFT])
    {
        entity.rotateDir = RotateDirection::rotateLeft;
    }
    else if (keyboardState[SDL_SCANCODE_RIGHT])
    {
       entity.rotateDir = RotateDirection::rotateRight;
    }
    else
    {
        entity.rotateDir = RotateDirection::rotateNone;
    }

    // Forward Movement
    if (keyboardState[SDL_SCANCODE_UP])
    {
        entity.moveDirX = MovementDirection::movementForward;
        entity.moveDirY = MovementDirection::movementForward;
    }
    else if (keyboardState[SDL_SCANCODE_DOWN])
    {
        entity.moveDirX = MovementDirection::movementBackwards;
        entity.moveDirY = MovementDirection::movementBackwards;
    }
    else
    {
        entity.moveDirX = MovementDirection::movementNone;
        entity.moveDirY = MovementDirection::movementNone;
    }

    // Actions
    if(actionEvent == SDLK_SPACE)
    {
        GameSystems::projectilePool->Create(entity.renderPosition, entity.renderRotation);
    }
}







