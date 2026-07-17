#pragma once
#include "GameEntity.h"
#include "CameraMoveEnum.h"

class CameraEntity : public GameEntity
{
public:
    CameraEntity(const CameraMoveEnum& cameraType_, const SDL_Rect& cameraRect_);
    void InterpolateCamPos(double alpha);

    CameraMoveEnum cameraType;
    SDL_Rect cameraRect;
};