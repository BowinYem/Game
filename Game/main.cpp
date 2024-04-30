#pragma once
#include <SDL3/SDL.h>

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* myWindow = SDL_CreateWindow("TestWindow", 480, 640, SDL_WINDOW_MAXIMIZED);
	SDL_Surface* WindowSurface = SDL_GetWindowSurface(myWindow);
	return 0;
}