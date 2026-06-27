#include "GameSystems.h"
#include "GameRenderer.h"
#include "GameWindow.h"

#include "GameEntity.h"
#include "EnemyEntity.h"
#include "EntityPool.h"
#include "SpriteComponent.h"
#include "PlayerInputComponent.h"
#include "PlayerPhysicsComponent.h"
#include "PlayerCollisionComponent.h"

#include "CollisionSystem.h"

#include <iostream> // TODO: DELETE 

bool GameSystems::quit = false;
const uint8_t* GameSystems::keyboardState = nullptr;
SDL_Keycode GameSystems::actionEvent;
const SDL_Color GameSystems::testColor = {0, 0, 0, 0xFF}; // Black

std::shared_ptr<GameRenderer> GameSystems::renderer{nullptr};
std::shared_ptr<GameWindow> GameSystems::window{nullptr};

std::shared_ptr<GameEntity> GameSystems::playerEntity{nullptr};
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

    window = std::make_shared<GameWindow>(GameWindowHeight, GameWindowWidth);
    if(!window) { InitSuccess = false; }

    renderer = std::make_shared<GameRenderer>();
    if(!renderer) { InitSuccess = false; }    

    collisionSys = std::make_shared<CollisionSystem>();
    if(!collisionSys) { InitSuccess = false; }

    // Create player entity
   	SDL_Rect CollisionBoxSize;
	CollisionBoxSize.h = 50;
	CollisionBoxSize.w = 50;
	playerEntity = std::make_shared<GameEntity>
	(
		std::make_shared<SpriteComponent>("star.bmp"),
		std::make_shared<PlayerInputComponent>(),
		std::make_shared<PlayerPhysicsComponent>(),
        std::make_shared<PlayerCollisionComponent>(CollisionBoxSize)
	);
    if(!playerEntity) { InitSuccess = false; }

    // Initialize Entity Pools
    enemyPool = std::make_shared<EntityPool<EnemyEntity>>(EnemyPoolSize);
    if(!enemyPool) { InitSuccess = false; }

    projectilePool= std::make_shared<EntityPool<ProjectileEntity>>(ProjectilePoolSize);
    if(!projectilePool) { InitSuccess = false; }

    return InitSuccess;
}

bool GameSystems::GameSystems_Close()
{
    return 1;
}

// void GameSystems::GameSystems_UpdateCollision()
// {
    //for(uint8_t currMeteor = 0; currMeteor < MeteorPoolSize; ++currMeteor)
    //{
    //    if(meteorPool->IsMeteorInUse(currMeteor))
    //    {
    //        auto& meteor = meteorPool->GetMeteor(currMeteor);

    //        for(uint8_t currProj = 0; currProj < ProjectilePoolSize; ++currProj)
    //        {
    //            if(projectilePool->IsProjectileInUse(currProj))
    //            {  
    //                auto& projectile = projectilePool->GetProjectile(currProj);

    //                bool projectileCollided = SDL_HasIntersection(&meteor.GetCollisionBox(), &projectile.GetCollisionBox());  
    //                if (projectileCollided)
    //                {
    //                    projectilePool->Destroy(currProj);
    //                    std::cout << "Projectile collided w/ Meteor. " << std::to_string(projectilePool->GetTotalActiveProjectiles()) << " remain." << std::endl;
    //                    meteorPool->Destroy(currMeteor);
    //                }
    //            }     
    //        }

    //        bool playerCollided = SDL_HasIntersection(&meteor.GetCollisionBox(), &playerEntity->GetCollisionBox()); 
    //        if (playerCollided)
    //        {
    //            // Player/Meteor collision logic goes here
    //            meteorPool->Destroy(currMeteor);
    //        }
    //    }
    //}

    //for(uint8_t currProj = 0; currProj < ProjectilePoolSize; ++currProj)
    //{
    //    if(projectilePool->IsProjectileInUse(currProj))
    //    {
    //        auto& projectile = projectilePool->GetProjectile(currProj);
    //        bool projectileOutOfBounds = (projectile.renderPosition.x > GameWindowWidth)                         ||
    //                            (projectile.renderPosition.x < (0.f - playerEntity->GetSpriteDimensions().w)     ||
    //                            (projectile.renderPosition.y > GameWindowHeight)                                 ||
    //                            (projectile.renderPosition.y < 0.f - playerEntity->GetSpriteDimensions().h));

    //        if(projectileOutOfBounds)
    //        { 
    //            projectilePool->Destroy(currProj); 
    //            std::cout << "Projectile out of bounds. " << std::to_string(projectilePool->GetTotalActiveProjectiles()) << " remain." << std::endl;
    //        }
    //    }
    //}
// }