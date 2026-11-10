#include "CameraInputComponent.h"
#include "GameSystems.h"
#include "CameraTypeEnum.h"
#include "InputSystem.h"

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
    auto inputSys = GameSystems::inputSys->GetInstance();

    if (inputSys->GetActionState(GameGlobals::ActionEnumType::ActionDebugCamUp))
    {
        camera.moveDirY = MovementDirection::movementBackwards;
    }
    else if (inputSys->GetActionState(GameGlobals::ActionEnumType::ActionDebugCamDown))  
    {
        camera.moveDirY = MovementDirection::movementForward;
    }
    else
    {
        camera.moveDirY = MovementDirection::movementNone;
    }

    if (inputSys->GetActionState(GameGlobals::ActionEnumType::ActionDebugCamRight)) 
    {
        camera.moveDirX = MovementDirection::movementForward;
    }
    else if (inputSys->GetActionState(GameGlobals::ActionEnumType::ActionDebugCamLeft))
    {
        camera.moveDirX = MovementDirection::movementBackwards;
    }
    else
    {
        camera.moveDirX = MovementDirection::movementNone;
    }
}

  


