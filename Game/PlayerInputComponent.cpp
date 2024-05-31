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
    auto keyboardState = GameSystems::keyboardState;

    // Rotation
    if (keyboardState[SDL_SCANCODE_LEFT])
    {
        entity.RotationVelocity = -1;
    }
    else if (keyboardState[SDL_SCANCODE_RIGHT])
    {
       entity.RotationVelocity = 1;
    }
    else
    {
        entity.RotationVelocity = 0;
    }

    // Forward Movement
    if (keyboardState[SDL_SCANCODE_UP])
    {
        entity.xVelocity = 5;
        entity.yVelocity = 5;
    }
    else if (keyboardState[SDL_SCANCODE_DOWN])
    {
        entity.xVelocity = -5;
        entity.yVelocity = -5;
    }
    else
    {
        entity.xVelocity = 0;
        entity.yVelocity = 0;
    }
}





