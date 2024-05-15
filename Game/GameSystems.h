#pragma once
#include <SDL.h>
#include <memory>

class GameRenderer;

class GameSystems
{
public:
	static inline std::shared_ptr<GameRenderer> GetRenderer() { return renderer;  }
	static inline SDL_Window* GetWindow() { return GameWindow;  }
	static void ReadInput();
	static bool GameSystems_Init();
	static bool GameSystems_Close();

public:
	static bool quit;
	static const uint8_t* keyboardState;

private:
	static std::shared_ptr<GameRenderer> renderer;
	static SDL_Window* GameWindow;
};

