#pragma once
#include <SDL.h>

class GameSystems
{
public:
	static GameSystems& GetGameSystems() { return Systems; }
	inline SDL_Renderer* GetRenderer() { return GameRenderer;  }
	inline SDL_Window* GetWindow() { return GameWindow;  }
	bool GameSystems_Init();
	bool GameSystems_Close();

private:
	static GameSystems Systems;
	SDL_Renderer* GameRenderer;
	SDL_Window* GameWindow;
};

