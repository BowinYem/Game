#pragma once
#include <SDL.h>

class GameWindow
{

friend class GameRenderer;

public:
	GameWindow();
	~GameWindow();

private:
	SDL_Window* windowSDLPtr;
};