#include "GameWindow.h"

GameWindow::GameWindow()
{
    windowSDLPtr = SDL_CreateWindow("TestWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
}

GameWindow::~GameWindow()
{
    SDL_DestroyWindow(windowSDLPtr);
    windowSDLPtr = nullptr;
}