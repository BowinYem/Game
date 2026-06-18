#include "TestInputComponent.h"
#include <SDL.h>
#include "GameEntity.h"

constexpr uint16_t TestInputComp_WaitTime = 1000;

TestInputComponent::TestInputComponent() : prevTime(SDL_GetTicks()){ }

void TestInputComponent::Update(GameEntity& entity)
{
    auto currentTime = SDL_GetTicks();
    auto elapsedTime = currentTime - prevTime;

    if(elapsedTime >= TestInputComp_WaitTime)
    { 
        entity.moveDir = (entity.moveDir == MovementDirection::movementNone) ? MovementDirection::movementForward : MovementDirection::movementNone;
        prevTime = currentTime;
    }

    entity.rotateDir = RotateDirection::rotateRight;
}
