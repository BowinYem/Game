#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <memory>

#include "GameEntity.h"
#include "GameSystems.h"
#include "GameRenderer.h"

#include "SpriteComponent.h"
#include "PlayerInputComponent.h"

static const char SPRITE_WIDTH = 30;
static const char SPRITE_HEIGHT = 31;
static const char TOTAL_WALK_CYCLE_FRAMES = 3;

bool quit = false;
std::vector<SDL_Rect> WallCycleFrames(3);

void loadSpriteSheet()
{
	WallCycleFrames[0] = { 0, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
	WallCycleFrames[1] = { 30, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
	WallCycleFrames[2] = { 60, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
}


std::unique_ptr<GameEntity> CreatePlayerEntity()
{
	// Create components here
	return std::make_unique<GameEntity>
		(
			std::make_unique<SpriteComponent>("star.bmp"),
			std::make_unique<PlayerInputComponent>()
		);
}

std::unique_ptr<GameEntity> CreateEntity()
{
	// Create components here
	return std::make_unique<GameEntity>
		(
			std::make_unique<SpriteComponent>("star.bmp"),
			nullptr
		);
}

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	GameSystems::GameSystems_Init();
	//SDL_Renderer* GameRenderer = GameSystems::GetRenderer();

	// Create entities with a sprite component
	std::vector<std::unique_ptr<GameEntity>> Entities;
	Entities.push_back(CreatePlayerEntity());
	Entities.push_back(CreateEntity());
	
	int currentFrame = 0;

	while (!GameSystems::quit)
	{
		GameSystems::ReadInput();
	
		GameSystems::GetRenderer()->GameRendererClear();

		Entities[0]->x = 100;
		Entities[0]->y = 100;
		Entities[0]->Update();

		Entities[1]->x = 300;
		Entities[1]->y = 300;
		Entities[1]->Update();

		GameSystems::GetRenderer()->GameRendererPresent();
	}

	return 0;
}


