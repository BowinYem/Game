#include "GameSystems.h"
#include "GameRenderer.h"
#include "GameWindow.h"

bool GameSystems::quit = false;
const uint8_t* GameSystems::keyboardState = nullptr;
const SDL_Color GameSystems::testColor = {0, 0, 0, 0xFF}; // Black

std::shared_ptr<GameRenderer> GameSystems::renderer{nullptr};
std::shared_ptr<GameWindow> GameSystems::window{nullptr};

std::unique_ptr<ProjectilePool> GameSystems::projectilePool(nullptr);
std::unique_ptr<MeteorPool> GameSystems::meteorPool(nullptr);

void GameSystems::ReadInput()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    { 
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
    }

    keyboardState = SDL_GetKeyboardState(nullptr);
}

bool GameSystems::GameSystems_Init()
{
    bool InitSuccess = true;

    window = std::make_shared<GameWindow>();
    if(!window) { InitSuccess = false; }

    renderer = std::make_shared<GameRenderer>();
    if(!renderer) { InitSuccess = false; }    

    projectilePool = std::make_unique<ProjectilePool>();
    if(!projectilePool) {InitSuccess = false; }

    meteorPool = std::make_unique<MeteorPool>();
    if(!meteorPool) {InitSuccess = false; }

    return InitSuccess;
}

bool GameSystems::GameSystems_Close()
{
    return 1;
}