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
static const float MS_PER_UPDATE = .01;
static const float FRAME_TIME_LIMIT = .25;

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
	newEntity->rotateDir = RotateDirection::rotateRight;
	newEntity->moveDir = MovementDirection::movementNone;
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

	double previousTime = SDL_GetTicks() / 1000.0f;
	double accumulator = 0.0; 
	double frameTime = 0;	

	while (!GameSystems::quit)
	{	
		double currentTime = SDL_GetTicks() / 1000.0f; 
		frameTime = currentTime - previousTime;
		if(frameTime > FRAME_TIME_LIMIT)
			{ frameTime = FRAME_TIME_LIMIT; }
		previousTime = currentTime;
		accumulator += frameTime;

		GameSystems::ReadInput();
	    GameSystems::playerEntity->UpdateInput();

		GameSystems::GetRenderer()->GameRendererClear();
		
		while (accumulator >= MS_PER_UPDATE) 
		{
			GameSystems::playerEntity->UpdatePhysics(MS_PER_UPDATE);
			GameSystems::GameSystems_UpdateCollision();
			accumulator -= MS_PER_UPDATE;
		}

		double alpha = accumulator / MS_PER_UPDATE;
		GameSystems::playerEntity->UpdateSprite(alpha);
		GameSystems::GetRenderer()->GameRendererPresent();
	}

	GameSystems::GameSystems_Close();

	return 0;
}


