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
	SpriteComponent(const std::string& filePath);
	
	~SpriteComponent();

	void Update(GameEntity& entity);
	
private:
	// void LoadSpriteRects(); // Implement animation on next iteration...

public:
	int16_t offsetX;
	int16_t offsetY;
	SDL_Rect srcRect;

private:
	// std::vector<SDL_Rect> SpriteRects; // Implement animation on next iteration...
	std::unique_ptr<GameTexture> spriteSheet;
};

