#include "GameEntity.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"

GameEntity::GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_, std::unique_ptr<InputComponent> InputComp_, std::unique_ptr<PhysicsComponent> PhysicsComp_) 
    : SpriteComp(std::move(SpriteComp_)), InputComp(std::move(InputComp_)), PhysicsComp(std::move(PhysicsComp_))
{
    // Constructor body...
    position.x = 100.f;
    position.y = 100.f;

    // Do this to center the entity postion onto the center of the sprite
    SpriteComp->offsetX = -(SpriteComp->srcRect.w / 2);
    SpriteComp->offsetY = -(SpriteComp->srcRect.h / 2);
}

GameEntity::~GameEntity()
{
    // Destructor body...
}

void GameEntity::Update()
{
    if(InputComp)
        { InputComp->Update(*this); }

    if(PhysicsComp)
        { PhysicsComp->Update(*this); }

    if(SpriteComp)
        { SpriteComp->Update(*this); } 
}



 