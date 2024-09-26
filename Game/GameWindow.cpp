#include "GameWindow.h"

GameWindow::GameWindow(uint16_t window_h, uint16_t window_w) : windowHeight(window_h), windowWidth(window_w)
{
    windowSDLPtr = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
}

GameWindow::~GameWindow()
{
    SDL_DestroyWindow(windowSDLPtr);
    windowSDLPtr = nullptr;
}