#include "GameEntity.h"
#include "SpriteComponent.h"
#include "InputComponent.h"

#include <math.h>   // ERASE AFTER TRAJECTORY DEBUGGING
#include "GameRenderer.h" // ERASE AFTER TRAJECTORY DEBUGGING
#include "GameSystems.h" // ERASE AFTER TRAJECTORY DEBUGGING

GameEntity::GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_, std::unique_ptr<InputComponent> InputComp_) : SpriteComp(std::move(SpriteComp_)), InputComp(std::move(InputComp_))
{
    // Constructor body...
    position.x = 100.f;
    position.y = 100.f;
}

GameEntity::~GameEntity()
{
    // Destructor body...
}

void GameEntity::Update()
{
    if(InputComp)
        { InputComp->Update(*this); }

    ///////////Temporary physics code - move this to a phyiscs component later /////////////// 

    position.x += xVelocity;
    position.y += yVelocity;
    rotation += rotationVelocity;

    constexpr double PI = 3.14159265358979323846;
    

    /////////////////////////

    SpriteComp->Update(*this);

    ////////////// Velocity, trajectory and direction  ////////////////

    float radians = rotation * (PI / 180);
    GameVector destPos { position.x + (100 * cos(radians)), position.y + (100 * sin(radians)) };
    GameSystems::GetRenderer()->GameRendererDrawLine(position, destPos);
    GameVector direction = destPos - position;
    
    /*
    Solution:    
    x2 = x1 + (L * cos(a))
    y2 = y1 + (L * sin(a))
    */
   
    //////////////////////////////////////////
}



 