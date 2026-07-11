#pragma once
#include "InputComponent.h"
#include "CameraMoveEnum.h"
#include "CameraEntity.h"

// Forward Declaration
class CameraEntity;

class CameraInputComponent : public InputComponent
{
public:
    void Update(GameEntity& camera) override;

private:
    void updatePlayerCamera(CameraEntity& camera);

    void updateDebugCamera(CameraEntity& camera);
};