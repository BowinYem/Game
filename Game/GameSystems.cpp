#include "GameSystems.h"
#include "GameRenderer.h"
#include "GameWindow.h"

#include "GameEntity.h"
#include "SpriteComponent.h"
#include "PlayerInputComponent.h"
#include "PhysicsComponent.h"

#include <iostream> // TODO: DELETE 

bool GameSystems::quit = false;
const uint8_t* GameSystems::keyboardState = nullptr;
SDL_Keycode GameSystems::actionEvent;
const SDL_Color GameSystems::testColor = {0, 0, 0, 0xFF}; // Black

std::shared_ptr<GameRenderer> GameSystems::renderer{nullptr};
std::shared_ptr<GameWindow> GameSystems::window{nullptr};

std::unique_ptr<ProjectilePool> GameSystems::projectilePool(nullptr);
std::unique_ptr<MeteorPool> GameSystems::meteorPool(nullptr);
std::shared_ptr<GameEntity> GameSystems::playerEntity(nullptr);

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

    projectilePool = std::make_unique<ProjectilePool>();
    if(!projectilePool) {InitSuccess = false; }

    meteorPool = std::make_unique<MeteorPool>();
    if(!meteorPool) {InitSuccess = false; }

    // Create player entity
   	SDL_Rect CollisionBoxSize;
	CollisionBoxSize.h = 50;
	CollisionBoxSize.w = 50;
	playerEntity = std::make_shared<GameEntity>
	(
		std::make_shared<SpriteComponent>("star.bmp"),
		std::make_shared<PlayerInputComponent>(),
		std::make_shared<PhysicsComponent>(CollisionBoxSize)
	);
    if(!playerEntity) { InitSuccess = false; }

    return InitSuccess;
}

bool GameSystems::GameSystems_Close()
{
    return 1;
}

void GameSystems::GameSystems_UpdateCollision()
{
    for(uint8_t i = 0; i < MeteorPoolSize; ++i)
    {
        if(meteorPool->IsMeteorInUse(i))
        {
            auto& meteor = meteorPool->GetMeteor(i);

            for(uint8_t j = 0; j < ProjectilePoolSize; ++j)
            {
                if(projectilePool->IsProjectileInUse(j))
                {  
                    auto& projectile = projectilePool->GetProjectile(j);

                    bool projectileCollided = SDL_HasIntersection(&meteor.GetCollisionBox(), &projectile.GetCollisionBox());  
                    if (projectileCollided)
                    {
                        projectilePool->Destroy(j);
                        std::cout << "Projectile collided w/ Meteor. " << std::to_string(projectilePool->GetTotalActiveProjectiles()) << " remain." << std::endl;
                        meteorPool->Destroy(i);
                    }

                    bool projectileOutOfBounds = (projectile.position.x > GameWindowWidth)                                  ||
                                                 (projectile.position.x < (0.f - playerEntity->GetSpriteDimensions().w)     ||
                                                 (projectile.position.y > GameWindowHeight)                                 ||
                                                 (projectile.position.y < 0.f - playerEntity->GetSpriteDimensions().h));
                    if(projectileOutOfBounds)
                    { 
                        projectilePool->Destroy(j); 
                        std::cout << "Projectile out of bounds. " << std::to_string(projectilePool->GetTotalActiveProjectiles()) << " remain." << std::endl;
                    }
                }     
            }

            bool playerCollided = SDL_HasIntersection(&meteor.GetCollisionBox(), &playerEntity->GetCollisionBox()); 
            if (playerCollided)
            {
                // Player/Meteor collision logic goes here
                meteorPool->Destroy(i);
            }
        }
    }
}