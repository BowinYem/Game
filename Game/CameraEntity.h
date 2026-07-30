#pragma once
#include "GameEntity.h"
#include "CameraTypeEnum.h"
#include "GameRect.h"

class CameraEntity : public GameEntity
{
public:
    CameraEntity(const CameraTypeEnum& cameraType_, const GameRect& cameraRect_);
    void InterpolateCamPos(const double alpha);

    CameraTypeEnum cameraType;
    GameRect cameraRect;
};