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

    GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_, std::unique_ptr<InputComponent> InputComp_, std::unique_ptr<PhysicsComponent> PhysicsComp_, GameVector SpawnLocation = {DefaultXPos, DefaultYPos});
    
    ~GameEntity();

    void Update();

    GameVector GetForwardDirection();

public:
    GameVector Position;
    int16_t Rotation = 0;

    int8_t xVelocity = 0;
    int8_t yVelocity = 0;
    double RotationVelocity = 0; 

private:
    std::unique_ptr<SpriteComponent> SpriteComp; 
    std::unique_ptr<InputComponent> InputComp;
    std::unique_ptr<PhysicsComponent> PhysicsComp;
};