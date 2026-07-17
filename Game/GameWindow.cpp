#include "GameWindow.h"
#include "GameSystems.h"

GameWindow::GameWindow(uint16_t window_w, uint16_t window_h) : windowWidth(window_w), windowHeight(window_h)
{
    windowSDLPtr = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, GameGlobals::CreateWindowFlags);
}

GameWindow::~GameWindow()
{
    SDL_DestroyWindow(windowSDLPtr);
    windowSDLPtr = nullptr;
}