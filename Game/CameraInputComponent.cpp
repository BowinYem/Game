#include "CameraInputComponent.h"
#include "GameSystems.h"
#include "CameraTypeEnum.h"

void CameraInputComponent::Update(GameEntity& entity)
{
    CameraEntity* camera = static_cast<CameraEntity*>(&entity);
    switch(camera->cameraType)
    {
        case CameraTypeEnum::PlayerCamera:
            UpdatePlayerCamera(*camera);
            break;
        
        case CameraTypeEnum::DebugCamera:
            UpdateDebugCamera(*camera);
            break;

        case CameraTypeEnum::StaticCamera:
            // Do nothing
            break;
    };
}

void CameraInputComponent::UpdatePlayerCamera(CameraEntity& camera)
{
    auto& cameraRect = camera.cameraRect;
    auto player = GameSystems::playerEntity;
    auto playerSize = player->GetSpriteDest();

    camera.physicsState.currPosition.x = (player->renderPosition.x + (playerSize.w / 2)) - (GameGlobals::GameLogicalWidth / 2);
    camera.physicsState.currPosition.y = (player->renderPosition.y + (playerSize.h / 2)) - (GameGlobals::GameLogicalHeight / 2);
}

void CameraInputComponent::UpdateDebugCamera(CameraEntity& camera)
{
    const uint8_t* keyboardState = GameSystems::keyboardState;
    auto& cameraRect = camera.cameraRect;

    if ((keyboardState[SDL_SCANCODE_W]))
    {
        camera.moveDirY = MovementDirection::movementBackwards;
    }
    else if ((keyboardState[SDL_SCANCODE_S]))  
    {
        camera.moveDirY = MovementDirection::movementForward;
    }
    else
    {
        camera.moveDirY = MovementDirection::movementNone;
    }

    if ((keyboardState[SDL_SCANCODE_D])) 
    {
        camera.moveDirX = MovementDirection::movementForward;
    }
    else if ((keyboardState[SDL_SCANCODE_A]))
    {
        camera.moveDirX = MovementDirection::movementBackwards;
    }
    else
    {
        camera.moveDirX = MovementDirection::movementNone;
    }
}

  


