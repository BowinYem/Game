#pragma once
#include "GameEntity.h"
#include "GameVector.h"
#include "CameraMoveEnum.h"

class CameraEntity : public GameEntity
{
public:
    CameraEntity(const CameraMoveEnum& cameraType_, const SDL_Rect& cameraRect_);
    SDL_Rect& getCameraRect() { return cameraRect; }
    void InterpolateCamPos(double alpha);
public:
    CameraMoveEnum cameraType;
private:
    SDL_Rect cameraRect;
};