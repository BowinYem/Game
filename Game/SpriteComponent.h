#pragma once
#include <SDL.h>
#include <string>
#include <vector>

class GameEntity;

class SpriteComponent
{
public:
	SpriteComponent(const std::string& FilePath);

	~SpriteComponent();

	void Update(GameEntity* Entity);
	
private:
	void LoadSpriteRects();

private:
	std::vector<SDL_Rect> SpriteRects; 
	SDL_Texture* SpriteSheet;
	SDL_Rect SpriteSourceRect;
	Uint8 TotalSprites;

	SDL_Renderer* GameRenderer;
	SDL_Window* GameWindow;
};