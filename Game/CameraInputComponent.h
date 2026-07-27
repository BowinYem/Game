#pragma once
#include "InputComponent.h"
#include "CameraEntity.h"
#include "GameEntity.h"

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