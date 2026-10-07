#include "CameraEntity.h"
#include "CollisionComponent.h"
#include "CameraInputComponent.h"
#include "LinearPhysicsComponent.h"
#include "GameSystems.h"

CameraEntity::CameraEntity(const CameraTypeEnum& cameraType_, const GameRect& cameraRect_): 
    GameEntity{ nullptr, // No sprite component
                std::make_shared<CameraInputComponent>(), 
                std::make_shared<LinearPhysicsComponent>(GameGlobals::CameraVelocity, GameGlobals::CameraVelocity), 
                std::make_shared<CollisionComponent>(CollisionEnum::collisionCamera, cameraRect_), // No specific collision component is created for CameraEntity because all it needs is boundary detection
                GameVector{cameraRect_.x, cameraRect_.y}}, 
    cameraType{cameraType_}, cameraRect{GetCollisionBox()} 
{ 
    //...
}

void CameraEntity::InterpolateCamPos(const double alpha)
{
    if(GameSystems::camera->cameraType == CameraTypeEnum::DebugCamera)
    {
        renderPosition.x = cameraRect.x = physicsState.prevPosition.x + ((physicsState.currPosition.x - physicsState.prevPosition.x) * alpha);
        renderPosition.y = cameraRect.y = physicsState.prevPosition.y + ((physicsState.currPosition.y - physicsState.prevPosition.y) * alpha);
    }
}