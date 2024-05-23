#include "PlayerInputComponent.h"
#include "GameSystems.h"
#include "GameEntity.h"
#include "GameRenderer.h" // REMOVE THIS 

#include <iostream>
#include <math.h>

constexpr double PI = 3.14159265358979323846;

// Helper functions
SDL_FPoint Normalize(const SDL_FPoint& point)
{
    float magnitude = sqrt(pow(point.x, 2) + pow(point.y, 2));
    float x2 = (point.x / magnitude);
    float y2 = (point.y / magnitude);
    return {x2, y2};
}

SDL_FPoint RotateVector(const SDL_FPoint& point, double angle)
{
    float radians = angle * (PI / 180);
    float cosVal = cos(radians);
    float sinVal = sin(radians);
    float x = (cosVal * point.x) - (sinVal * point.y);
    float y = (cosVal * point.x) + (sinVal * point.y);
    return {x, y};
}

SDL_FPoint CalculateVelocity(const SDL_FPoint& point, float rotation)     // needs to be class memeber?
{
    // Rotate current posiotn
    // normalize 

    auto rotatedPoint = RotateVector(point, rotation);
    return Normalize(rotatedPoint);
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

    // Rotation
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

    // Forward Movement
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


    ////////////// DEBUG CODE ////////////////

    float radians = entity.rotation * (PI / 180);
    float x2 = entity.x + (100 * cos(radians));
    float y2 = entity.y + (100 * sin(radians));
    SDL_FPoint destPoint { x2, y2 };

    GameSystems::GetRenderer()->GameRendererDrawLine({ entity.x, entity.y }, destPoint);
  
    /*
    Solution:    
    x2 = x1 + (L * cos(a))
    y2 = y1 + (L * sin(a))
    */
   
    //////////////////////////////////////////
}





