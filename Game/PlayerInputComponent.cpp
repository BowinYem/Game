#include "PlayerInputComponent.h"
#include "GameSystems.h"
#include "GameEntity.h"

#include <iostream>
#include <math.h>

constexpr double PI = 3.14159265358979323846;

// Helper functions
void Normalize(const SDL_Point& point)
{
    double magnitude = sqrt(pow(point.x, 2) + pow(point.y, 2));
    double x2 = (point.x / magnitude);
    double y2 = (point.y / magnitude);
}

void RotateVector(const SDL_Point& point, double angle)
{
    double radians = angle * (PI / 180);
    double cosVal = cos(radians);
    double sinVal = sin(radians);
    double x = (cosVal * point.x) - (sinVal * point.y);
    double y = (cosVal * point.x) + (sinVal * point.y);
}


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

    // X movement
    if (keyboardState[SDL_SCANCODE_LEFT])
    {
        entity.rotationVelocity = -1;
    }
    else if (keyboardState[SDL_SCANCODE_RIGHT])
    {
       entity.rotationVelocity = 1;
    }
    else
    {
        entity.rotationVelocity = 0;
    }

    // Y movement
    if (keyboardState[SDL_SCANCODE_UP])
    {
        entity.yVelocity = -5;
    }
    else if (keyboardState[SDL_SCANCODE_DOWN])
    {
        entity.yVelocity = 5;
    }
    else
    {
        entity.yVelocity = 0;
    }

    RotateVector(SDL_Point{1, 1}, 90.f);

}





