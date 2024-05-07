#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "GameEntity.h"
#include "SpriteComponent.h"

SDL_Renderer* GameRenderer = nullptr;
SDL_Window* GameWindow = nullptr;

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

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	GameWindow = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	GameRenderer = SDL_CreateRenderer(GameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // use bitwise OR operand to pass multiple flags 
	SDL_SetRenderDrawColor(GameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	// Loading a texture

	SpriteComponent TestSprite("star.bmp");

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
		SDL_RenderPresent(GameRenderer);
	}

	SDL_DestroyWindow(GameWindow);
	
	return 0;
}