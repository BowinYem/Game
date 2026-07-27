#pragma once
#include "InputComponent.h"
#include "GameEntity.h"

// Forward declarations
class GameEntity;

class PlayerInputComponent : public InputComponent
{
public:
	void Update(GameEntity& entity) override; 
};
