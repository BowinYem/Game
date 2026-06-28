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

#include "EntityPool.h"

#include <iostream>

static const char SPRITE_WIDTH = 30;
static const char SPRITE_HEIGHT = 31;
static const float MS_PER_UPDATE = .01;
static const float FRAME_TIME_LIMIT = .25;

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	GameSystems::GameSystems_Init();

	auto enemyPool = GameSystems::enemyPool;
	enemyPool->Create(GameVector(100, 100), 0);
	enemyPool->Create(GameVector(200, 200), 0);
	enemyPool->Create(GameVector(300, 300), 0);

	auto projPool = GameSystems::projectilePool;

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
		enemyPool->UpdateInput();
		projPool->UpdateInput();

		GameSystems::GetRenderer()->GameRendererClear();
		
		while (accumulator >= MS_PER_UPDATE) 
		{
			GameSystems::playerEntity->UpdatePhysics(MS_PER_UPDATE);
			enemyPool->UpdatePhysics(MS_PER_UPDATE);
			projPool->UpdatePhysics(MS_PER_UPDATE);

			GameSystems::playerEntity->UpdateCollision();
			enemyPool->UpdateCollision();
			projPool->UpdateCollision();

			accumulator -= MS_PER_UPDATE;
		}

		GameSystems::gameBG->Update();

		double alpha = accumulator / MS_PER_UPDATE;
		GameSystems::playerEntity->UpdateSprite(alpha);
		enemyPool->UpdateSprite(alpha);
		projPool->UpdateSprite(alpha);

		GameSystems::GetRenderer()->GameRendererPresent();
	}

	GameSystems::GameSystems_Close();

	return 0;
}


