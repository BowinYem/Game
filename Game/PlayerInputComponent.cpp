#include "PlayerInputComponent.h"
#include "GameSystems.h"
#include "GameEntity.h"

PlayerInputComponent::PlayerInputComponent()
{
    // Constructor body...
}

PlayerInputComponent::~PlayerInputComponent()
{
    // Destructor body...
}

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
        entity.moveDir = MovementDirection::movementForward;
    }
    else if (keyboardState[SDL_SCANCODE_DOWN])
    {
        entity.moveDir = MovementDirection::movementBackwards;
    }
    else
    {
        entity.moveDir = MovementDirection::movementNone;
    }

    // Actions
    if(actionEvent == SDLK_SPACE)
    {
        //GameSystems::projectilePool->Create(entity.renderPosition, entity.renderRotation);
    }
}







