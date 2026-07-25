#pragma once
#include <SDL.h>
#include <memory>
#include "EntityPool.h"
#include "GameRenderer.h"
#include "GameWindow.h"
#include "GameEntity.h"
#include "EnemyEntity.h"
#include "ProjectileEntity.h"
#include "CameraEntity.h"
#include "GameBackground.h"
#include "CollisionSystem.h"
#include "GameGlobals.h"

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

	GameSystems() = delete;
	~GameSystems() = delete;
	GameSystems(const GameSystems&) = delete;
	GameSystems(GameSystems&&) = delete;
	GameSystems& operator=(const GameSystems&) = delete;
	GameSystems& operator=(GameSystems&&) = delete;

	static inline std::shared_ptr<GameRenderer> GetRenderer() { return renderer;  }
	static inline std::shared_ptr<GameWindow> GetWindow() { return window;  }
	static void ReadInput();
	static bool GameSystems_Init();
	static bool GameSystems_Close();

	static bool quit;

	static const uint8_t* keyboardState;
	static SDL_Keycode actionEvent;

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