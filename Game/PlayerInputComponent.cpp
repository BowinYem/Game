#include "PlayerInputComponent.h"
#include "GameSystems.h"
#include <iostream>


PlayerInputComponent::PlayerInputComponent()
{

}

PlayerInputComponent::~PlayerInputComponent()
{

}

void PlayerInputComponent::Update()
{
    // Do basic input handling here for now
    auto keyboardState = GameSystems::keyboardState;

    if (keyboardState[SDL_SCANCODE_LEFT])
    {
       std::cout << "LEFT" << std::endl;
    }
}

