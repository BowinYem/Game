#pragma once

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
    SpriteComponent* SpriteComp;
};