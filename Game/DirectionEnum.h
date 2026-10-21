#pragma once
#include <stdint.h>
#include "EnumOperators.h"

enum class MovementDirection : int8_t
{
    movementBackwards = -1,
    movementNone,
    movementForward
};

enum class RotateDirection : int8_t
{
    rotateLeft = -1,
    rotateNone,
    rotateRight
};

