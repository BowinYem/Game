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
    void UpdatePlayerCamera(CameraEntity& camera);
    void UpdateDebugCamera(CameraEntity& camera);
};