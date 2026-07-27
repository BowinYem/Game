// InputComponent is an interface for input components

#pragma once
#include "GameEntity.h"

// Forward declarations
class GameEntity;

class InputComponent
{
public:
	virtual void Update(GameEntity& entity) = 0;
};