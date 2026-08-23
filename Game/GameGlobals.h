#pragma once
#include <stdint.h>
#include <string_view>
#include "SDL.h"
#include "CameraTypeEnum.h"
#include "GameRect.h"
namespace GameGlobals
{
    inline constexpr uint16_t GameLogicalWidth = 1000;
    inline constexpr uint16_t GameLogicalHeight = 563;

    inline constexpr uint16_t GameWindowWidth = 1280;
    inline constexpr uint16_t GameWindowHeight = 720;
    inline constexpr uint16_t CreateWindowFlags = 0;

    inline constexpr SDL_Color FinalRenderDrawColor{ 0x00, 0x00, 0x00, 0x00 };
    inline constexpr SDL_Color TestColor { 0x00, 0x00, 0x00, 0x00 };
    inline constexpr SDL_Color SpriteChromaColor { 0x00, 0xFF, 0xFF, 0x00 };

    inline constexpr uint16_t GameLevelWidth = 1200; 
    inline constexpr uint16_t GameLevelHeight = 1200;

    inline constexpr uint16_t PlayerSpawnX = 100;
    inline constexpr uint16_t PlayerSpawnY = 100;
    inline constexpr std::string_view PlayerSpriteFile = "star.bmp";
    inline constexpr double PlayerVelocity = 100.0f;
    inline constexpr double PlayerRotateVelocity = 100.0f;
    const GameRect PlayerCollisionBox{0, 0, 50, 50};

    // Temporary variables - will be deleted with future update
    inline constexpr uint8_t ProjectilePoolSize = 5; 
    inline constexpr double  ProjectileVelocity = 250.0f;
    inline constexpr double  ProjectileRotateVelocity = 100.0f;
    const GameRect ProjectileCollisionBox{0, 0, 50, 50};
    inline constexpr std::string_view ProjectileSpriteFile = "star.bmp";
    inline constexpr double  ProjectileDespawnThreshold = 100;

    // Temporary variables - will be deleted with future update
    inline constexpr uint8_t EnemyPoolSize = 5;
    inline constexpr double  EnemyVelocity = 100.0f;
    inline constexpr double  EnemyRotateVelocity = 100.0f;  
    const GameRect enemyCollisionBox{0, 0, 50, 50};
    inline constexpr std::string_view enemySpriteFile = "star.bmp";

    inline constexpr std::string_view BGFilePath = "bg.bmp";
    inline constexpr CameraTypeEnum StartingCameraType = CameraTypeEnum::PlayerCamera; 
    const GameRect StartingCameraRect{0, 0, GameGlobals::GameLogicalWidth, GameLogicalHeight}; 
}