#pragma once
#include <SDL.h>
#include <memory>
#include "ProjectilePool.h"
#include "MeteorPool.h"

// Forward declarations
class GameRenderer;
class GameWindow;

class GameSystems
{
public:
	static inline std::shared_ptr<GameRenderer> GetRenderer() { return renderer;  }
	static inline std::shared_ptr<GameWindow> GetWindow() { return window;  }
	static void ReadInput();
	static bool GameSystems_Init();
	static bool GameSystems_Close();

public:
	static bool quit;
	static const uint8_t* keyboardState;
	static std::unique_ptr<ProjectilePool> projectilePool;
	static std::unique_ptr<MeteorPool> meteorPool;

private:
	static std::shared_ptr<GameRenderer> renderer;
	static std::shared_ptr<GameWindow> window;
};

