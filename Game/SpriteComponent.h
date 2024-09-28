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
	
	void Update(GameEntity& entity);

	SpriteComponent& operator= (SpriteComponent& otherComp); 

	const SDL_Rect& GetSpriteDimenisions();

public:
	SDL_Rect srcRect;
	SDL_Rect destRect;

private:
	std::shared_ptr<GameTexture> spriteSheet;
};

