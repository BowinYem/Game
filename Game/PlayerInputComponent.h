#pragma once
#include "InputComponent.h"
#include <cstdint>

// Forward declarations
class GameEntity;

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();
	~PlayerInputComponent();
	virtual void Update(GameEntity& entity) override; 
};

