#include "CollisionComponent.h"
#include "CollisionEnum.h"
#include "GameRect.h"
#include "GameEntity.h"

class CameraCollisionComponent: public CollisionComponent
{
public:
    CameraCollisionComponent(const GameRect& cameraRect_ = {0.0f, 0.0f, 0.0f, 0.0f});
    void Update(GameEntity& entity) override;
};