#pragma once
#include <SDL.h>

class GameSystems
{
public:
	static inline SDL_Renderer* GetRenderer() { return GameRenderer;  }
	static inline SDL_Window* GetWindow() { return GameWindow;  }
	static void ReadInput();
	static bool GameSystems_Init();
	static bool GameSystems_Close();

public:
	static bool quit;
	static const uint8_t* keyboardState;

private:
	static SDL_Renderer* GameRenderer;
	static SDL_Window* GameWindow;
};

