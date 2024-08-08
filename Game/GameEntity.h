#pragma once
#include <memory>
#include <string> 
#include "GameVector.h"
#include "SDL.h"

constexpr double DefaultXPos = 100.f;
constexpr double DefaultYPos = 100.f;

class SpriteComponent;
class InputComponent;
class PhysicsComponent;

class GameEntity
{
public:

    GameEntity();

    GameEntity(std::unique_ptr<SpriteComponent> spriteComp_, std::unique_ptr<InputComponent> inputComp_, std::unique_ptr<PhysicsComponent> physicsComp_, GameVector spawnLocation = {DefaultXPos, DefaultYPos});
    
    ~GameEntity();

    void Update();

    GameVector GetForwardDirection();

    void SetSpriteComponent(std::shared_ptr<SpriteComponent> spriteComp_);

    void SetInputComponent(std::unique_ptr<InputComponent> inputComp_);

    void SetPhysicsComponent(std::unique_ptr<PhysicsComponent> physicsComp_);

    const SDL_Rect& GetCollisionBox();


public:
    GameVector position;
    GameVector positionOffset; 

    int16_t rotation = 0;

    int8_t xVelocity = 0;
    int8_t yVelocity = 0;
    double rotationVelocity = 0; 

private:
    std::shared_ptr<SpriteComponent> spriteComp {nullptr}; 
    std::unique_ptr<InputComponent> inputComp {nullptr};
    std::unique_ptr<PhysicsComponent> physicsComp {nullptr};
};