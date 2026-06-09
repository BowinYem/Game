#pragma once
#include <stdint.h>
#include <type_traits>

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

template <typename T>
constexpr auto operator+ (T a) noexcept
{
    return static_cast<std::underlying_type_t<T>>(a);
}