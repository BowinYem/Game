#include "GameEntity.h"

GameEntity::GameEntity(SpriteComponent* SpriteComp_) : SpriteComp(SpriteComp_)
{
    
}

GameEntity::~GameEntity()
{
    // Make sure to delete/free the Sprite component
}

void GameEntity::Update()
{
    x = 300; y = 300;
    SpriteComp->Update(this);
}