#pragma once

// Forward declarations
class GameEntity;

class InputComponent
{
public:
	~InputComponent();
	
	virtual void Update(GameEntity& entity) = 0;
};