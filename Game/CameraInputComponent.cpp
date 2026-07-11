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

    cameraRect.x = (player->renderPosition.x + (playerSize.w / 2)) - (GameWindowWidth / 2);
    cameraRect.y = (player->renderPosition.y + (playerSize.h / 2)) - (GameWindowHeight / 2);

    if(cameraRect.x < 0) 
        { cameraRect.x = 0; }
    
    if (cameraRect.y < 0) 
        { cameraRect.y = 0; }

    if(cameraRect.x > (GameLevelWidth - cameraRect.w)) 
        { cameraRect.x = GameLevelWidth - cameraRect.w; }

    if (cameraRect.y > (GameLevelHeight - cameraRect.h))  
        { cameraRect.y = GameLevelHeight - cameraRect.h; }
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
    else if ((keyboardState[SDL_SCANCODE_S]) && (cameraRect.y < (GameLevelHeight - cameraRect.h)))  
    {
        camera.moveDirY = MovementDirection::movementForward;
    }
    else
    {
        camera.moveDirY = MovementDirection::movementNone;
    }

    if ((keyboardState[SDL_SCANCODE_D]) && (cameraRect.x < (GameLevelWidth - cameraRect.w))) 
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

  


