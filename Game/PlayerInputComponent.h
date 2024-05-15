#pragma once
#include "InputComponent.h"

// Forward declarations
class GameEntity;

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();
	~PlayerInputComponent();
	void Update(GameEntity& entity); 

private:

};

