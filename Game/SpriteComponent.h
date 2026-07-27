#pragma once

#include <SDL.h>
#include <string>
#include <memory>

#include "GameEntity.h"
#include "GameTexture.h"

// Forward Declarations
class GameEntity;

class SpriteComponent
{
public:

	SpriteComponent(const std::string& filePath);
	
	virtual void Update(GameEntity& entity, const double alpha);

	SDL_Rect srcRect;
	SDL_FRect destRect;

private:
	void interpolate(GameEntity& entity, const double alpha);
	std::shared_ptr<GameTexture> spriteSheet;
};