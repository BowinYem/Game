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
#include "PhysicsComponent.h"

#include "ProjectilePool.h"

#include <iostream>

static const char SPRITE_WIDTH = 30;
static const char SPRITE_HEIGHT = 31;
static const char TOTAL_WALK_CYCLE_FRAMES = 3;
static const char MS_PER_UPDATE = 16;

std::unique_ptr<GameEntity> CreatePlayerEntity()
{
	SDL_Rect CollisionBoxSize;
	CollisionBoxSize.h = 50;
	CollisionBoxSize.w = 50;

	// Create components here
	return std::make_unique<GameEntity>
		(
			std::make_shared<SpriteComponent>("star.bmp"),
			std::make_shared<PlayerInputComponent>(),
			std::make_shared<PhysicsComponent>(CollisionBoxSize)
		);
}

std::unique_ptr<GameEntity> CreateEntity()
{
	// Create components here
	auto newEntity = std::make_unique<GameEntity>
		(
			std::make_shared<SpriteComponent>("star.bmp"),
			nullptr,
			std::make_shared<PhysicsComponent>()
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
	//Entities.push_back(CreatePlayerEntity());
	Entities.push_back(CreateEntity());
	
	// ProjectilePool testPool;
	//GameSystems::projectilePool->Create({200, 400}, 0);
	GameSystems::meteorPool->Create({400, 400}, 0);

	//GameSystems::projectilePool->Create({200, 300}, 0);
	GameSystems::meteorPool->Create({400, 300}, 0);

	//GameSystems::projectilePool->Create({200, 200}, 0);
	GameSystems::meteorPool->Create({400, 200}, 0);

	uint32_t previousTime = SDL_GetTicks();
	uint32_t lagTime = 0;	

	while (!GameSystems::quit)
	{
		uint32_t currentTime = SDL_GetTicks(); 
		uint32_t elapsedTime = currentTime - previousTime;
		previousTime = currentTime;
		lagTime += elapsedTime;

		GameSystems::ReadInput();
	
		GameSystems::GetRenderer()->GameRendererClear();
		
		while (lagTime >= MS_PER_UPDATE) 
		{
			lagTime -= MS_PER_UPDATE;
			GameSystems::playerEntity->Update();
			Entities[0]->Update();

			GameSystems::projectilePool->Update();
			GameSystems::meteorPool->Update();
			GameSystems::GameSystems_UpdateCollision();
		}
		GameSystems::GetRenderer()->GameRendererPresent();
	}

	GameSystems::GameSystems_Close();

	return 0;
}


