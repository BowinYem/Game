#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include <memory>

// Forward Declarations
class GameEntity;
class GameTexture;
class GameVector;

class SpriteComponent
{
public:

	SpriteComponent(const std::string& filePath);
	
	virtual void Update(GameEntity& entity, double alpha);

	SpriteComponent& operator= (SpriteComponent& otherComp); 

	const SDL_Rect& GetSpriteDimenisions();

public:
	SDL_Rect srcRect;
	SDL_FRect destRect;

private:
	void interpolate(GameEntity& entity, double alpha);
	std::shared_ptr<GameTexture> spriteSheet;
};

