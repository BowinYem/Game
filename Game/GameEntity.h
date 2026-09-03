#pragma once
#include "SDL.h"

#include <memory>
#include <string> 

#include "GameVector.h"
#include "GameRect.h"
#include "PhysicsState.h"
#include "DirectionEnum.h"

#include "SpriteComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "CollisionComponent.h"

// Forward declarations
class SpriteComponent;
class InputComponent;
class PhysicsComponent;
class CollisionComponent;

class GameEntity
{
public:

    GameEntity(const std::shared_ptr<SpriteComponent>    spriteComp_, 
               const std::shared_ptr<InputComponent>     inputComp_, 
               const std::shared_ptr<PhysicsComponent>   physicsComp_, 
               const std::shared_ptr<CollisionComponent> collisionComp_, 
               const GameVector& spawnLocation = {0, 0});
    
    virtual void UpdatePhysics(const double dt);

    virtual void UpdateInput();

    virtual void UpdateSprite(const double alpha);

    virtual void UpdateCollision();

    inline void SetSpriteComponent(const std::shared_ptr<SpriteComponent> spriteComp_);

    inline void SetInputComponent(const std::shared_ptr<InputComponent> inputComp_);

    inline void SetPhysicsComponent(const std::shared_ptr<PhysicsComponent> physicsComp_);

    inline void SetCollisionComponent(const std::shared_ptr<CollisionComponent> collisionComp_);

    GameVector GetForwardDirection() const;

    GameRect& GetCollisionBox();

    const GameRect& GetSpriteDest();

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