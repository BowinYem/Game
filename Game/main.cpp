#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>


static const char SPRITE_WIDTH = 40;
static const char SPRITE_HEIGHT = 40;

bool quit = false;
std::vector<SDL_Rect> SheetRects(4);


void loadSpriteSheed()
{
	SheetRects[0] = { 0, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
	SheetRects[1] = { 40, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
	SheetRects[2] = { 80, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
	SheetRects[3] = { 120, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
}

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* myWindow = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	SDL_Renderer* TestRenderer = SDL_CreateRenderer(myWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(TestRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	// Loading a texture
	SDL_Surface* TestSurface = IMG_Load("count.bmp");
	SDL_SetColorKey(TestSurface, SDL_TRUE, SDL_MapRGB(TestSurface->format, 115, 251, 253));
	SDL_Texture* TestTexture = SDL_CreateTextureFromSurface(TestRenderer, TestSurface);
	SDL_FreeSurface(TestSurface);
	TestSurface = nullptr;
	SDL_Rect SrcRect = { 120, 0, 40, 40 };
	SDL_Rect DestRect = { 300, 300, 40, 40 };

	SDL_Event e;
	
	while (!quit)
	{
		while(SDL_PollEvent(&e))
		{ 
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_RenderClear(TestRenderer);
		SDL_RenderCopy(TestRenderer, TestTexture, &SrcRect, &DestRect);
		SDL_RenderPresent(TestRenderer);

		const Uint8* KeyBoardState = nullptr;
		KeyBoardState = SDL_GetKeyboardState(nullptr);

		if (KeyBoardState[SDL_SCANCODE_LEFT])
		{
			std::cout << "LEFT arrow pressed" << std::endl;
		}

		if (KeyBoardState[SDL_SCANCODE_RIGHT])
		{
			std::cout << "RIGHT arrow pressed" << std::endl;
		}
	}

	



	SDL_DestroyWindow(myWindow);
	

	return 0;
}