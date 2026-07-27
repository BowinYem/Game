#pragma once
#include <SDL.h>

class GameWindow
{

friend class GameRenderer;

public:
	GameWindow() = delete;
	GameWindow(const GameWindow&) = delete;
	GameWindow(GameWindow&&) = delete;
	GameWindow& operator=(const GameWindow&) = delete;
	GameWindow& operator=(GameWindow&&) = delete;
	
	GameWindow(const uint16_t window_w, const uint16_t window_h);
	~GameWindow();

	uint16_t windowWidth;
	uint16_t windowHeight;

private:
	SDL_Window* windowSDLPtr;
};