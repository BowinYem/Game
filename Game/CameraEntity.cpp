#include "CameraEntity.h"
#include "CameraInputComponent.h"
#include "LinearPhysicsComponent.h"
#include "GameSystems.h"

CameraEntity::CameraEntity(const CameraTypeEnum& cameraType_, const SDL_Rect& cameraRect_) : 
    GameEntity{nullptr, std::make_shared<CameraInputComponent>(), std::make_shared<LinearPhysicsComponent>(), nullptr, GameVector{static_cast<double>(cameraRect_.x), static_cast<double>(cameraRect_.y)}}, 
    cameraType{cameraType_}, cameraRect{cameraRect_} 
{ 

}

void CameraEntity::InterpolateCamPos(double alpha)
{
    if(GameSystems::camera->cameraType == CameraTypeEnum::DebugCamera)
    {
        renderPosition.x = cameraRect.x = physicsState.prevPosition.x + ((physicsState.currPosition.x - physicsState.prevPosition.x) * alpha);
        renderPosition.y = cameraRect.y = physicsState.prevPosition.y + ((physicsState.currPosition.y - physicsState.prevPosition.y) * alpha);
    }
}