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
	void LoadSpriteRects();

private:
	std::vector<SDL_Rect> SpriteRects;
	std::unique_ptr<GameTexture> SpriteSheet;
	SDL_Rect SpriteSourceRect;
	Uint8 TotalSprites;
};

