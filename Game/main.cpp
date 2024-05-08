#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "GameEntity.h"
#include "SpriteComponent.h"
#include "GameSystems.h"

static const char SPRITE_WIDTH = 30;
static const char SPRITE_HEIGHT = 31;
static const char TOTAL_WALK_CYCLE_FRAMES = 3;

bool quit = false;
std::vector<SDL_Rect> WallCycleFrames(3);

void loadSpriteSheet()
{
	WallCycleFrames[0] = { 0, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
	WallCycleFrames[1] = { 30, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
	WallCycleFrames[2] = { 60, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
}


GameEntity* CreateEntity()
{
	return new GameEntity(new SpriteComponent("star.bmp"));
}

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	GameSystems::GetGameSystems().GameSystems_Init();
	SDL_Renderer* GameRenderer = GameSystems::GetGameSystems().GetRenderer();

	// Create entities with a sprite component
	std::vector<GameEntity*> Entities;
	Entities.push_back(CreateEntity());
	Entities.push_back(CreateEntity());

	SDL_Event e;
	
	int currentFrame = 0;

	while (!quit)
	{
		while(SDL_PollEvent(&e))
		{ 
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		const Uint8* KeyBoardState = nullptr;
		KeyBoardState = SDL_GetKeyboardState(nullptr);

		//if (KeyBoardState[SDL_SCANCODE_LEFT])
		//{

		//}
	
		//currentSprite = WallCycleFrames[currentFrame / (TOTAL_WALK_CYCLE_FRAMES * 3)];
		++currentFrame;
		if((currentFrame / (TOTAL_WALK_CYCLE_FRAMES * 3)) >= TOTAL_WALK_CYCLE_FRAMES)
		{
			currentFrame = 0;
		}

		SDL_RenderClear(GameRenderer);

	
		Entities[0]->x = 100;
		Entities[0]->y = 100;
		Entities[0]->Update();

		Entities[1]->x = 300;
		Entities[1]->y = 300;
		Entities[1]->Update();

		SDL_RenderPresent(GameRenderer);
	}

	return 0;
}


