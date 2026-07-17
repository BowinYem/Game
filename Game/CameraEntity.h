#pragma once
#include "GameEntity.h"
#include "CameraTypeEnum.h"

class CameraEntity : public GameEntity
{
public:
    CameraEntity(const CameraTypeEnum& cameraType_, const SDL_Rect& cameraRect_);
    void InterpolateCamPos(double alpha);

    CameraTypeEnum cameraType;
    SDL_Rect cameraRect;
};