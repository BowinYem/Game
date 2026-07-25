#include "GameVector.h"
#include "GameMath.h"
#include <math.h>

GameVector::GameVector(const double x_, const double y_) : x{x_}, y{y_} 
{
    //...
}

void GameVector::Normalize()
{
    float magnitude = sqrt(pow(x, 2) + pow(y, 2));
    x = (x / magnitude);
    y = (y / magnitude);
}

void GameVector::Rotate(const float angleDegree)
{
    float angleRadians = GameMath::DegreesToRadians(angleDegree);
    float cosVal = cos(angleRadians);
    float sinVal = sin(angleRadians);
    x = (cosVal * x) - (sinVal * y);
    y = (cosVal * x) + (sinVal * y);
}

GameVector operator+(const GameVector& v1, const GameVector& v2)
{
    return GameVector(v1.x + v2.x, v1.y + v2.y);
}

GameVector operator-(const GameVector& v)
{
    return GameVector{-v.x, -v.y};
}

GameVector operator-(const GameVector& v1, const GameVector& v2)
{
    return GameVector{v1 + (-v2)};
}