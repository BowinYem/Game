#pragma once
#include <memory>

class SpriteComponent;
class InputComponent;

class GameEntity
{
public:

    GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_, std::unique_ptr<InputComponent> InputComp_);
    
    ~GameEntity();

    void Update();

public:
    float x = 100.0f;
    float y = 100.0f;
    double rotation = 90;

    int16_t xVelocity = 0;
    int16_t yVelocity = 0;
    double rotationVelocity = 0; 
    
private:
    std::unique_ptr<SpriteComponent> SpriteComp; 
    std::unique_ptr<InputComponent> InputComp;
};