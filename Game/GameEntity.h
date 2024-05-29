#pragma once
#include <memory>
#include "GameVector.h"

class SpriteComponent;
class InputComponent;
class PhysicsComponent;

class GameEntity
{
public:

    GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_, std::unique_ptr<InputComponent> InputComp_, std::unique_ptr<PhysicsComponent> PhysicsComp_);
    
    ~GameEntity();

    void Update();

public:
    GameVector position;
    double rotation = 0.f;

    int8_t xVelocity = 0;
    int8_t yVelocity = 0;
    double rotationVelocity = 0; 
    
private:
    std::unique_ptr<SpriteComponent> SpriteComp; 
    std::unique_ptr<InputComponent> InputComp;
    std::unique_ptr<PhysicsComponent> PhysicsComp;
};