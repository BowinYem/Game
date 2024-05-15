#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include <memory>

// Forward Declarations
class GameEntity;
class GameTexture;

class SpriteComponent
{
public:
	SpriteComponent(const std::string& FilePath);
	
	~SpriteComponent();

	void Update(const GameEntity& Entity);
	
private:
	// void LoadSpriteRects(); // Implement animation on next iteration...


public:


private:
	// std::vector<SDL_Rect> SpriteRects; // Implement animation on next iteration...
	std::unique_ptr<GameTexture> SpriteSheet;
	SDL_Rect srcRect;
	uint8_t TotalSprites;
};

