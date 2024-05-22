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

    SDL_FPoint destPoint = RotateVector({ entity.x, entity.y }, entity.rotation);
    GameSystems::GetRenderer()->GameRendererDrawLine({ entity.x, entity.y }, destPoint);

    //SDL_FPoint newPoint = RotateVector(destPoint, 45.f);
    //SDL_FPoint newPoint2 = Normalize(newPoint);
    //SDL_FPoint newPoint3 = { newPoint2.x * 2, newPoint2.y * 2 };

    //GameSystems::GetRenderer()->GameRendererDrawLine({ entity.x, entity.y }, newPoint3);

    /*
    // Go off of velocity instead of current position

    Given that vector v is {0, 1}

    To calculate the velocity of an entity, 
        1. calculate v2 by rotating v by the entity's current rotation
        2. v3 = normalize(v2)  
        3.  x = v3.x * speed
            y = v3.y * speed


    */

    /*
      Approach #2 - Find the directional vector?

    */

   
    

    //////////////////////////////////////////
}





