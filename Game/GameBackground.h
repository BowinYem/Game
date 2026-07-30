#pragma once
#include "GameTexture.h"
#include "string.h" 
#include "GameRect.h"

class GameBackground
{
public:
    GameBackground(const std::string& filePath);
    void Update();

private:
    GameRect destRect;     
    GameTexture bgTexture;
};
