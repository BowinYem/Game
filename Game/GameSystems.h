#pragma once
#include <SDL.h>
#include <memory>
#include "EntityPool.h"
#include "EnemyEntity.h"
#include "CameraEntity.h"
#include "ProjectileEntity.h"
#include "GameRenderer.h"
#include "GameBackground.h"

// Constants
constexpr uint16_t GameWindowWidth = 1920;
constexpr uint16_t GameWindowHeight = 1920;
constexpr uint16_t GameLevelWidth = 1200; 
constexpr uint16_t GameLevelHeight = 1200;

constexpr uint8_t EnemyPoolSize = 5;
constexpr uint8_t ProjectilePoolSize = 5; 

// Forward declarations
class GameRenderer;
class GameWindow;
class GameEntity;
class CameraEntity;
class GameBackground;
class CollisionSystem;

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
	static SDL_Keycode actionEvent;

	static const SDL_Color testColor;	

	static std::shared_ptr<GameBackground> gameBG;

	static std::shared_ptr<GameEntity> playerEntity; 
	static std::shared_ptr<CameraEntity> camera;
	static std::shared_ptr<EntityPool<EnemyEntity>> enemyPool;
	static std::shared_ptr<EntityPool<ProjectileEntity>> projectilePool;

	static std::shared_ptr<CollisionSystem> collisionSys;

private:
	static std::shared_ptr<GameRenderer> renderer;
	static std::shared_ptr<GameWindow> window;
};

