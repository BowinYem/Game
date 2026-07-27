#pragma once
#include "InputComponent.h"
#include "GameEntity.h"

class ProjectileInputComponent : public InputComponent
{
public:
	void Update(GameEntity& entity) override;
};