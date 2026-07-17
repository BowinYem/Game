#include "GameSystems.h"
#include "GameRenderer.h"
#include "GameWindow.h"

#include "GameEntity.h"
#include "GameBackground.h"
#include "EnemyEntity.h"
#include "CameraEntity.h"
#include "EntityPool.h"
#include "SpriteComponent.h"
#include "PlayerInputComponent.h"
#include "TestInputComponent.h"
#include "RotatePhysicsComponent.h"
#include "PlayerCollisionComponent.h"

#include "CollisionSystem.h"

#include <iostream> // TODO: DELETE 

bool GameSystems::quit = false;
const uint8_t* GameSystems::keyboardState = nullptr;
SDL_Keycode GameSystems::actionEvent;
const SDL_Color GameSystems::testColor = {0, 0, 0, 0xFF}; // Black

std::shared_ptr<GameRenderer> GameSystems::renderer{nullptr};
std::shared_ptr<GameWindow> GameSystems::window{nullptr};

std::shared_ptr<GameBackground> GameSystems::gameBG{nullptr};

std::shared_ptr<GameEntity> GameSystems::playerEntity{nullptr};
std::shared_ptr<CameraEntity> GameSystems::camera{nullptr};
std::shared_ptr<EntityPool<EnemyEntity>> GameSystems::enemyPool{nullptr};
std::shared_ptr<EntityPool<ProjectileEntity>> GameSystems::projectilePool{nullptr};

std::shared_ptr<CollisionSystem> GameSystems::collisionSys{nullptr};


void GameSystems::ReadInput()
{
    actionEvent = SDLK_UNKNOWN;
    SDL_Event event;

    while(SDL_PollEvent(&event))
    { 
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
        else if(event.type == SDL_KEYUP)
        {
            actionEvent = event.key.keysym.sym;
        }
    }

    keyboardState = SDL_GetKeyboardState(nullptr);
}

bool GameSystems::GameSystems_Init()
{
    bool InitSuccess = true;

    window = std::make_shared<GameWindow>(GameGlobals::GameWindowWidth, GameGlobals::GameWindowHeight);
    if(!window) { InitSuccess = false; }

    renderer = std::make_shared<GameRenderer>();
    if(!renderer) { InitSuccess = false; }    

    collisionSys = std::make_shared<CollisionSystem>();
    if(!collisionSys) { InitSuccess = false; }


    // Initialize Background
    gameBG = std::make_shared<GameBackground>(std::string(GameGlobals::BGFilePath));
    if(!gameBG) { InitSuccess = false; }

    // Create camera Entity
    camera = std::make_shared<CameraEntity>(GameGlobals::StartingCameraType, GameGlobals::StartingCameraRect);
    if(!camera) { InitSuccess = false; }

    // Create player entity
   	SDL_Rect CollisionBoxSize;
	CollisionBoxSize.h = 50;
	CollisionBoxSize.w = 50;
	playerEntity = std::make_shared<GameEntity>
	(
		std::make_shared<SpriteComponent>("star.bmp"),
		std::make_shared<PlayerInputComponent>(),
		std::make_shared<RotatePhysicsComponent>(),
        std::make_shared<PlayerCollisionComponent>(CollisionBoxSize)
	);
    if(!playerEntity) { InitSuccess = false; }

    // Initialize Entity Pools
    enemyPool = std::make_shared<EntityPool<EnemyEntity>>(GameGlobals::EnemyPoolSize);
    if(!enemyPool) { InitSuccess = false; }

    projectilePool= std::make_shared<EntityPool<ProjectileEntity>>(GameGlobals::ProjectilePoolSize);
    if(!projectilePool) { InitSuccess = false; }

    return InitSuccess;
}

bool GameSystems::GameSystems_Close()
{
    return 1;
}
