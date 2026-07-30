#pragma once

#include <string>
#include <memory>

#include "GameRect.h"
#include "GameEntity.h"
#include "GameTexture.h"

// Forward Declarations
class GameEntity;

class SpriteComponent
{
public:

	SpriteComponent(const std::string& filePath);
	
	virtual void Update(GameEntity& entity, const double alpha);

	GameRect srcRect;
	GameRect destRect;

private:
	void interpolate(GameEntity& entity, const double alpha);
	std::shared_ptr<GameTexture> spriteSheet;
};