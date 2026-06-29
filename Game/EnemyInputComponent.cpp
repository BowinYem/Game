#include "EnemyInputComponent.h"
#include <SDL.h>
#include "GameEntity.h"

constexpr uint16_t TestInputComp_WaitTime = 1000;

EnemyInputComponent::EnemyInputComponent() : prevTime(SDL_GetTicks()){ }

void EnemyInputComponent::Update(GameEntity& entity)
{
    auto currentTime = SDL_GetTicks();
    auto elapsedTime = currentTime - prevTime;

    if(elapsedTime >= TestInputComp_WaitTime)
    { 
        entity.moveDirX = (entity.moveDirX == MovementDirection::movementNone) ? MovementDirection::movementForward : MovementDirection::movementNone;
        entity.moveDirY = (entity.moveDirY == MovementDirection::movementNone) ? MovementDirection::movementForward : MovementDirection::movementNone;
        prevTime = currentTime;
    }

    entity.rotateDir = RotateDirection::rotateRight;
}
