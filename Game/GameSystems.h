#pragma once
#include <SDL.h>
#include <memory>
#include "ProjectilePool.h"
#include "MeteorPool.h"

// Constants
constexpr uint16_t GameWindowHeight = 480;
constexpr uint16_t GameWindowWidth = 640; 

// Forward declarations
class GameRenderer;
class GameWindow;
class GameEntity;

class GameSystems
{
public:
	static inline std::shared_ptr<GameRenderer> GetRenderer() { return renderer;  }
	static inline std::shared_ptr<GameWindow> GetWindow() { return window;  }
	static void ReadInput();
	static bool GameSystems_Init();
	static bool GameSystems_Close();
	static void GameSystems_UpdateCollision();

public:
	static bool quit;
	static const uint8_t* keyboardState;
	static SDL_Keycode actionEvent;
	static std::unique_ptr<ProjectilePool> projectilePool;
	static std::unique_ptr<MeteorPool> meteorPool;
	static std::shared_ptr<GameEntity> playerEntity; 
	static const SDL_Color testColor; 

private:
	static std::shared_ptr<GameRenderer> renderer;
	static std::shared_ptr<GameWindow> window;
};

