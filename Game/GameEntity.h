#pragma once
#include <memory>
#include "GameVector.h"

constexpr double DefaultXPos = 100.f;
constexpr double DefaultYPos = 100.f;

class SpriteComponent;
class InputComponent;
class PhysicsComponent;

class GameEntity
{
public:

    GameEntity(std::unique_ptr<SpriteComponent> spriteComp_, std::unique_ptr<InputComponent> inputComp_, std::unique_ptr<PhysicsComponent> physicsComp_, GameVector spawnLocation = {DefaultXPos, DefaultYPos});
    
    ~GameEntity();

    void Update();

    GameVector GetForwardDirection();

    void SetSpriteComponent(std::unique_ptr<SpriteComponent> spriteComp__);

    void SetInputComponent(std::unique_ptr<InputComponent> inputComp__);

    void SetPhysicsComponen(std::unique_ptr<PhysicsComponent> PhysicsComponent);


public:
    GameVector position;
    int16_t rotation = 0;

    int8_t xVelocity = 0;
    int8_t yVelocity = 0;
    double rotationVelocity = 0; 

private:
    std::unique_ptr<SpriteComponent> spriteComp; 
    std::unique_ptr<InputComponent> inputComp;
    std::unique_ptr<PhysicsComponent> physicsComp;
};