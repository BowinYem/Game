#pragma once
#include <stdint.h>
#include <string_view>
#include "SDL.h"
#include "CameraMoveEnum.h"

namespace GameGlobals
{
    inline constexpr uint16_t GameLogicalWidth = 1000;
    inline constexpr uint16_t GameLogicalHeight = 563;

    inline constexpr uint16_t GameWindowWidth = 1280;
    inline constexpr uint16_t GameWindowHeight = 720;
    inline constexpr uint16_t CreateWindowFlags = 0;

    inline constexpr uint16_t GameLevelWidth = 1200; 
    inline constexpr uint16_t GameLevelHeight = 1200;

    inline constexpr uint8_t EnemyPoolSize = 5;
    inline constexpr uint8_t ProjectilePoolSize = 5; 

    inline constexpr std::string_view BGFilePath = "bg.bmp";
    inline constexpr CameraMoveEnum InitCameraType = CameraMoveEnum::PlayerCamera; 
    inline constexpr SDL_Rect CameraSize{0, 0, GameGlobals::GameLogicalWidth, GameLogicalHeight}; 
}