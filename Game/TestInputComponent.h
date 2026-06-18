#pragma once
#include "InputComponent.h"
#include <stdint.h>

class TestInputComponent : public InputComponent
{
public:
    TestInputComponent();
    void Update(GameEntity& entity) override;
private:
    uint32_t prevTime;
};