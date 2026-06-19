#pragma once
#include "SDL.h"

#include <memory>
#include <string> 

#include "GameVector.h"
#include "PhysicsState.h"
#include "DirectionEnum.h"

#include "SpriteComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"

constexpr double DefaultXPos = 100.f;
constexpr double DefaultYPos = 100.f;

enum class EntityType;

class GameEntity
{
public:

    GameEntity() = default;

    GameEntity(std::shared_ptr<SpriteComponent> spriteComp_, std::shared_ptr<InputComponent> inputComp_, std::shared_ptr<PhysicsComponent> physicsComp_, GameVector spawnLocation = {DefaultXPos, DefaultYPos});
    
    void UpdatePhysics(double extrapolateVal);

    void UpdateInput();

    void UpdateSprite(double alpha);

    GameVector GetForwardDirection();

    void SetSpriteComponent(std::shared_ptr<SpriteComponent> spriteComp_);

    void SetInputComponent(std::shared_ptr<InputComponent> inputComp_);

    void SetPhysicsComponent(std::shared_ptr<PhysicsComponent> physicsComp_);

    const SDL_Rect& GetCollisionBox();

    const SDL_Rect& GetSpriteDimensions();

public:
    EntityType entityType;

    GameVector renderPosition;
    double renderRotation = 0;

	MovementDirection moveDir = MovementDirection::movementNone;
	RotateDirection rotateDir = RotateDirection::rotateNone; 
    PhysicsState physicsState;

private:
    std::shared_ptr<SpriteComponent> spriteComp {nullptr}; 
    std::shared_ptr<InputComponent> inputComp {nullptr};
    std::shared_ptr<PhysicsComponent> physicsComp {nullptr};
};
