#include "GameEntity.h"
#include "SpriteComponent.h"
#include "InputComponent.h"

GameEntity::GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_, std::unique_ptr<InputComponent> InputComp_) : SpriteComp(std::move(SpriteComp_)), InputComp(std::move(InputComp_))
{
    // Constructor body...   
}

GameEntity::~GameEntity()
{
    // Destructor body...
}

void GameEntity::Update()
{
    SpriteComp->Update(*this);

    if(InputComp)
        { InputComp->Update(); }
}