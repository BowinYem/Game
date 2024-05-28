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
	auto newEntity = std::make_unique<GameEntity>
		(
			std::make_unique<SpriteComponent>("star.bmp"),
			nullptr
		);
	
	// This kind of entity just rotates in place at this specific spot
	newEntity->rotationVelocity = 5.f;
	newEntity->position.x = 300;
	newEntity->position.y = 300;
	return newEntity;
}

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	GameSystems::GameSystems_Init();

	// Create entities with a sprite component
	std::vector<std::unique_ptr<GameEntity>> Entities;
	Entities.push_back(CreatePlayerEntity());
	Entities.push_back(CreateEntity());
	
	while (!GameSystems::quit)
	{
		GameSystems::ReadInput();
	
		GameSystems::GetRenderer()->GameRendererClear();

		Entities[0]->Update();
		Entities[1]->Update();

		GameSystems::GetRenderer()->GameRendererPresent();
	}

	return 0;
}


