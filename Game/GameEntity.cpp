#include "GameEntity.h"
#include "SpriteComponent.h"

GameEntity::GameEntity(std::unique_ptr<SpriteComponent> SpriteComp_) : SpriteComp(std::move(SpriteComp_))
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
}