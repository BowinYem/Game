#pragma once
#include <memory>

class SpriteComponent;

class GameEntity
{
public:

    GameEntity(SpriteComponent* SpriteComp_);
    ~GameEntity();

    void Update();

    int x;
    int y;

private:
    //SpriteComponent* SpriteComp;
    std::unique_ptr<SpriteComponent> SpriteComp; 
};