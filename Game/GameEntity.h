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
#include "CollisionComponent.h"

constexpr double DefaultXPos = 100.f;
constexpr double DefaultYPos = 100.f;

class CollisionComponent;
class GameEntity
{
public:

    GameEntity() = default;

    GameEntity(std::shared_ptr<SpriteComponent> spriteComp_, std::shared_ptr<InputComponent> inputComp_, std::shared_ptr<PhysicsComponent> physicsComp_, std::shared_ptr<CollisionComponent> collisionComp_, 
        GameVector spawnLocation = {DefaultXPos, DefaultYPos});
    
    virtual void UpdatePhysics(double extrapolateVal);

    virtual void UpdateInput();

    virtual void UpdateSprite(double alpha);

    virtual void UpdateCollision();

    GameVector GetForwardDirection();

    void SetSpriteComponent(std::shared_ptr<SpriteComponent> spriteComp_);

    void SetInputComponent(std::shared_ptr<InputComponent> inputComp_);

    void SetPhysicsComponent(std::shared_ptr<PhysicsComponent> physicsComp_);

    void SetCollisionComponent(std::shared_ptr<CollisionComponent> collisionComp_);

    const SDL_Rect& GetCollisionBox();

    const SDL_Rect& GetSpriteDimensions();

public:
    GameVector renderPosition;
    double renderRotation = 0;

	MovementDirection moveDirX = MovementDirection::movementNone;
    MovementDirection moveDirY = MovementDirection::movementNone;
	RotateDirection rotateDir = RotateDirection::rotateNone; 
    PhysicsState physicsState;

private:
    std::shared_ptr<SpriteComponent> spriteComp {nullptr}; 
    std::shared_ptr<InputComponent> inputComp {nullptr};
    std::shared_ptr<PhysicsComponent> physicsComp {nullptr};
    std::shared_ptr<CollisionComponent> collisionComp {nullptr};
};
