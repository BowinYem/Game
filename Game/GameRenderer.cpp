#include "GameRenderer.h"
#include <string>

enum
{
    FIRST_AVAILABLE_DRIVER = 1
    // Define more enums down the line?
};

static const Uint8 RENDER_DRAW_COLOR_R = 0xFF;
static const Uint8 RENDER_DRAW_COLOR_G = 0xFF;
static const Uint8 RENDER_DRAW_COLOR_B = 0xFF;
static const Uint8 RENDER_DRAW_COLOR_A = 0xFF;

static const Uint16 WINDOW_WIDTH = 640;
static const Uint16 WINDOW_HEIGHT = 480;

static const std::string WindowName("GAME WINDOW");  

GameRenderer* GameRenderer::GetRenderer()
{
    static GameRenderer* RendererInstance = new GameRenderer();
    return RendererInstance;
}


inline int GameRenderer::GameRendererClear()
{
    SDL_RenderClear(Renderer);
}

inline void GameRenderer::GameRendererPresent()
{
    SDL_RenderPresent(Renderer);
}

GameRenderer::GameRenderer()
{
    GameWindow = SDL_CreateWindow(WindowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    Renderer = SDL_CreateRenderer(GameWindow, FIRST_AVAILABLE_DRIVER, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(Renderer, RENDER_DRAW_COLOR_R, RENDER_DRAW_COLOR_G, RENDER_DRAW_COLOR_B, RENDER_DRAW_COLOR_A);
}

GameRenderer::~GameRenderer()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(GameWindow);
}
