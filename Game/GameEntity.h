#pragma once
#include <memory>
#include <string> 
#include "GameVector.h"
#include "SDL.h"

constexpr double DefaultXPos = 100.f;
constexpr double DefaultYPos = 100.f;

class SpriteComponent;
class InputComponent;
class PhysicsComponent;
enum class EntityType;

class GameEntity
{
public:

    GameEntity() = default;

    GameEntity(std::shared_ptr<SpriteComponent> spriteComp_, std::shared_ptr<InputComponent> inputComp_, std::shared_ptr<PhysicsComponent> physicsComp_, EntityType entityType_, GameVector spawnLocation = {DefaultXPos, DefaultYPos});
    
    void Update();

    GameVector GetForwardDirection();

    void SetSpriteComponent(std::shared_ptr<SpriteComponent> spriteComp_);

    void SetInputComponent(std::shared_ptr<InputComponent> inputComp_);

    void SetPhysicsComponent(std::shared_ptr<PhysicsComponent> physicsComp_);

    const SDL_Rect& GetCollisionBox();


public:
    EntityType entityType;

    GameVector position;
    int16_t rotation = 0;

    int8_t xVelocity = 0;
    int8_t yVelocity = 0;
    double rotationVelocity = 0; 

private:
    std::shared_ptr<SpriteComponent> spriteComp {nullptr}; 
    std::shared_ptr<InputComponent> inputComp {nullptr};
    std::shared_ptr<PhysicsComponent> physicsComp {nullptr};
};

enum class EntityType
{
    PlayerEntity,
    ProjectileEntity,
    MeteorEntity,
    OtherEntity 
};