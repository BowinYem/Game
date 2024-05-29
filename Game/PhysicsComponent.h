#pragma once

class GameEntity;

class PhysicsComponent
{
 public:
    PhysicsComponent();
    ~PhysicsComponent();
    void Update(GameEntity& entity);
};