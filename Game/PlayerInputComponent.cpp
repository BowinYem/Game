#include "PlayerInputComponent.h"
#include "GameSystems.h"
#include "GameEntity.h"

#include <iostream>

PlayerInputComponent::PlayerInputComponent()
{

}

PlayerInputComponent::~PlayerInputComponent()
{

}

void PlayerInputComponent::Update(GameEntity& entity)
{
    // Do basic input handling here for now
    auto keyboardState = GameSystems::keyboardState;

    if (keyboardState[SDL_SCANCODE_LEFT])
    {
        entity.xVelocity = -5;
    }
    else
    {
        entity.xVelocity = 0;
    }

    if (keyboardState[SDL_SCANCODE_RIGHT])
    {
       entity.xVelocity = 5;
    }
    else
    {
        entity.xVelocity = 0;
    }
}

