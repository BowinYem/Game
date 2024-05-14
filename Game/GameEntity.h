#pragma once
#include <memory>

class SpriteComponent;

class GameEntity
{
public:

    GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_);
    ~GameEntity();

    void Update();

    int x;
    int y;

private:
    std::unique_ptr<SpriteComponent> SpriteComp; 
};