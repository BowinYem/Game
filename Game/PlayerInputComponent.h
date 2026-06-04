#pragma once
#include "InputComponent.h"
#include <cstdint>

constexpr double DefaultMovementRate = 100.0;
constexpr double DefaultRotationRate = 100.0;

// Forward declarations
class GameEntity;

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();
	~PlayerInputComponent();
	void Update(GameEntity& entity); 

private:
	int8_t movementRate = DefaultMovementRate;
	int8_t rotationRate = DefaultRotationRate;
};

