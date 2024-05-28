#pragma once
#include <memory>
#include "GameVector.h"

class SpriteComponent;
class InputComponent;

class GameEntity
{
public:

    GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_, std::unique_ptr<InputComponent> InputComp_);
    
    ~GameEntity();

    void Update();

public:
    GameVector position;
    double rotation = -90;

    int16_t xVelocity = 0;
    int16_t yVelocity = 0;
    double rotationVelocity = 0; 
    
private:
    std::unique_ptr<SpriteComponent> SpriteComp; 
    std::unique_ptr<InputComponent> InputComp;
};