#pragma once
#include <SDL.h>

class GameWindow
{

friend class GameRenderer;

public:
	GameWindow() = delete;
	GameWindow(uint16_t window_h, uint16_t window_w);
	~GameWindow();

private:
	SDL_Window* windowSDLPtr;
	uint16_t windowHeight;
	uint16_t windowWidth;
};