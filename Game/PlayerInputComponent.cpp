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

    // Rotation
    if (keyboardState[SDL_SCANCODE_LEFT])
    {
        entity.rotationVelocity = -rotationRate;
    }
    else if (keyboardState[SDL_SCANCODE_RIGHT])
    {
       entity.rotationVelocity = rotationRate;
    }
    else
    {
        entity.rotationVelocity = 0;
    }

    // Forward Movement
    if (keyboardState[SDL_SCANCODE_UP])
    {
        entity.xVelocity = movementRate;
        entity.yVelocity = movementRate;
    }
    else if (keyboardState[SDL_SCANCODE_DOWN])
    {
        entity.xVelocity = -movementRate;
        entity.yVelocity = -movementRate;
    }
    else
    {
        entity.xVelocity = 0;
        entity.yVelocity = 0;
    }


}







