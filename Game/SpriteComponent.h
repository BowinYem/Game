#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include "GameEntity.h"

extern SDL_Renderer* GameRenderer; // Replace with some kind of general game system singleton?
extern SDL_Window* GameWindow;	// Replace with some kind of general game system singleton?

class SpriteComponent
{
public:
	SpriteComponent(const std::string& FilePath);

	//~SpriteComponent();

	void Update(GameEntity* Entity);
	
private:
	void LoadSpriteRects();

private:
	std::vector<SDL_Rect> SpriteRects; 
	SDL_Texture* SpriteSheet;
	SDL_Rect SpriteSourceRect;
	Uint8 TotalSprites;
};