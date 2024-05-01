#pragma once
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* myWindow = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	SDL_Renderer* TestRenderer = SDL_CreateRenderer(myWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(TestRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	SDL_Surface* TestSurface = IMG_Load("star.bmp");
	SDL_Texture* TestTexture = SDL_CreateTextureFromSurface(TestRenderer, TestSurface);
	SDL_FreeSurface(TestSurface);
	TestSurface = nullptr;
	SDL_Rect SrcRect = { 0, 0, 40, 40 };
	SDL_Rect DestRect = { 300, 300, 40, 40 };

	while (true)
	{
		SDL_RenderClear(TestRenderer);
		SDL_RenderCopy(TestRenderer, TestTexture, &SrcRect, &DestRect);
		SDL_RenderPresent(TestRenderer);
	}
	

	return 0;
}