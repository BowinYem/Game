#pragma once
#include <SDL.h>
#include <string>


class SpriteComponent
{
public:
	SpriteComponent(const std::string& FilePath, const SDL_Rect& SheetSize_, const SDL_Rect& SpriteSize_, Uint8 TotalSprites_ = 1);

	~SpriteComponent();

	void Update();
	
private:
	SDL_Texture* SpriteSheet;
	SDL_Rect SheetSize;
	SDL_Rect SpriteSize;
	Uint8 TotalSprites;
};