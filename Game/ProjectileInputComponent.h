#pragma once
#include "InputComponent.h"

class ProjectileInputComponent : public InputComponent
{
public:
	void Update(GameEntity& entity) override;
};