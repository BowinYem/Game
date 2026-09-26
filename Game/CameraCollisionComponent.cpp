#include "CameraCollisionComponent.h"
#include "CameraCollisionComponent.h"

CameraCollisionComponent::CameraCollisionComponent(const GameRect& cameraRect_) : 
    CollisionComponent(CollisionEnum::collisionCamera, cameraRect_)
{
    //...
}

void CameraCollisionComponent::Update(GameEntity& entity)
{
    CollisionComponent::DetectCollisions(entity);
}

