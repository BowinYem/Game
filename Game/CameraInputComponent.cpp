#include "CameraInputComponent.h"
#include "GameSystems.h"

void CameraInputComponent::Update(GameEntity& entity)
{
    CameraEntity* camera = static_cast<CameraEntity*>(&entity);
    switch(camera->cameraType)
    {
        case CameraMoveEnum::PlayerCamera:
            updatePlayerCamera(*camera);
            break;
        
        case CameraMoveEnum::DebugCamera:
            updateDebugCamera(*camera);
            break;

        case CameraMoveEnum::StaticCamera:
            // Do nothing
            break;
    };
}

void CameraInputComponent::updatePlayerCamera(CameraEntity& camera)
{
    auto& cameraRect = camera.getCameraRect();
    auto player = GameSystems::playerEntity;
    auto playerSize = player->GetSpriteDimensions();

    cameraRect.x = (player->renderPosition.x + (playerSize.w / 2)) - (GameLogicalWidth / 2);
    cameraRect.y = (player->renderPosition.y + (playerSize.h / 2)) - (GameLogicalHeight / 2);

    if(cameraRect.x < 0) 
        { cameraRect.x = 0; }
    
    if (cameraRect.y < 0) 
        { cameraRect.y = 0; }

    if(cameraRect.x > (GameLevelWidth - GameLogicalWidth))      
        { cameraRect.x = GameLevelWidth - GameLogicalWidth; }

    if (cameraRect.y > (GameLevelHeight - GameLogicalHeight))  
        { cameraRect.y = GameLevelHeight - GameLogicalHeight; }
}

void CameraInputComponent::updateDebugCamera(CameraEntity& camera)
{
    const uint8_t* keyboardState = GameSystems::keyboardState;
    SDL_Keycode actionEvent = GameSystems::actionEvent;
    auto& cameraRect = camera.getCameraRect();

    if ((keyboardState[SDL_SCANCODE_W]) && (cameraRect.y > 0))
    {
        camera.moveDirY = MovementDirection::movementBackwards;
    }
    else if ((keyboardState[SDL_SCANCODE_S]) && (cameraRect.y < (GameLevelHeight - GameLogicalHeight)))  
    {
        camera.moveDirY = MovementDirection::movementForward;
    }
    else
    {
        camera.moveDirY = MovementDirection::movementNone;
    }

    if ((keyboardState[SDL_SCANCODE_D]) && (cameraRect.x < (GameLevelWidth - GameLogicalWidth))) 
    {
        camera.moveDirX = MovementDirection::movementForward;
    }
    else if ((keyboardState[SDL_SCANCODE_A]) && (cameraRect.x > 0))
    {
        camera.moveDirX = MovementDirection::movementBackwards;
    }
    else
    {
        camera.moveDirX = MovementDirection::movementNone;
    }

}

  


