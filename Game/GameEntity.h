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

    int x;
    int y;

private:
    std::unique_ptr<SpriteComponent> SpriteComp; 
    std::unique_ptr<InputComponent> InputComp;
};