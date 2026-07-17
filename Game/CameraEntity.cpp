#include "CameraEntity.h"
#include "CameraInputComponent.h"
#include "LinearPhysicsComponent.h"
#include "GameSystems.h"

CameraEntity::CameraEntity(const CameraMoveEnum& cameraType_, const SDL_Rect& cameraRect_) : GameEntity{nullptr, std::make_shared<CameraInputComponent>(),
    std::make_shared<LinearPhysicsComponent>(), nullptr}, cameraType{cameraType_}, cameraRect{cameraRect_} 
{
    GameEntity::physicsState.currPosition.x = cameraRect.x;
    GameEntity::physicsState.currPosition.y = cameraRect.y;
}

void CameraEntity::InterpolateCamPos(double alpha)
{
    if(GameSystems::camera->cameraType == CameraMoveEnum::DebugCamera)
    {
        renderPosition.x = cameraRect.x = physicsState.prevPosition.x + ((physicsState.currPosition.x - physicsState.prevPosition.x) * alpha);
        renderPosition.y = cameraRect.y = physicsState.prevPosition.y + ((physicsState.currPosition.y - physicsState.prevPosition.y) * alpha);
    }
}