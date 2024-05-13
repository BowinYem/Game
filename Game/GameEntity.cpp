#include "GameEntity.h"
#include "SpriteComponent.h"

GameEntity::GameEntity(SpriteComponent* SpriteComp_) : SpriteComp(SpriteComp_)
{
    
}

GameEntity::~GameEntity()
{
    //delete SpriteComp;
}

void GameEntity::Update()
{
    SpriteComp->Update(*this);
}