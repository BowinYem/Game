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
    auto& cameraRect = camera.cameraRect;
    auto player = GameSystems::playerEntity;
    auto playerSize = player->GetSpriteDimensions();

    cameraRect.x = (player->renderPosition.x + (playerSize.w / 2)) - (GameGlobals::GameLogicalWidth / 2);
    cameraRect.y = (player->renderPosition.y + (playerSize.h / 2)) - (GameGlobals::GameLogicalHeight / 2);

    if(cameraRect.x < 0) 
        { cameraRect.x = 0; }
    
    if (cameraRect.y < 0) 
        { cameraRect.y = 0; }

    if(cameraRect.x > (GameGlobals::GameLevelWidth - GameGlobals::GameLogicalWidth))      
        { cameraRect.x = GameGlobals::GameLevelWidth - GameGlobals::GameLogicalWidth; }

    if (cameraRect.y > (GameGlobals::GameLevelHeight - GameGlobals::GameLogicalHeight))  
        { cameraRect.y = GameGlobals::GameLevelHeight - GameGlobals::GameLogicalHeight; }
}

void CameraInputComponent::updateDebugCamera(CameraEntity& camera)
{
    const uint8_t* keyboardState = GameSystems::keyboardState;
    SDL_Keycode actionEvent = GameSystems::actionEvent;
    auto& cameraRect = camera.cameraRect;

    if ((keyboardState[SDL_SCANCODE_W]) && (cameraRect.y > 0))
    {
        camera.moveDirY = MovementDirection::movementBackwards;
    }
    else if ((keyboardState[SDL_SCANCODE_S]) && (cameraRect.y < (GameGlobals::GameLevelHeight - GameGlobals::GameLogicalHeight)))  
    {
        camera.moveDirY = MovementDirection::movementForward;
    }
    else
    {
        camera.moveDirY = MovementDirection::movementNone;
    }

    if ((keyboardState[SDL_SCANCODE_D]) && (cameraRect.x < (GameGlobals::GameLevelWidth - GameGlobals::GameLogicalWidth))) 
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

  


