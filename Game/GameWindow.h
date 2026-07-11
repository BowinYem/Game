#pragma once
#include <SDL.h>

class GameWindow
{

friend class GameRenderer;

public:
	GameWindow() = delete;
	GameWindow(uint16_t window_w, uint16_t window_h);
	~GameWindow();

private:
	SDL_Window* windowSDLPtr;
	uint16_t windowWidth;
	uint16_t windowHeight;
};