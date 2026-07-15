#pragma once
#include "InputComponent.h"

class TestInputComponent : public InputComponent
{
public:
    void Update(GameEntity& entity) override;
};