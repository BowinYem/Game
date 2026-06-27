#pragma once
#include "InputComponent.h"
#include <stdint.h>

class EnemyInputComponent : public InputComponent
{
public:
    EnemyInputComponent();
    void Update(GameEntity& entity) override;
private:
    uint32_t prevTime;
};