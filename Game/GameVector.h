#pragma once

class GameVector
{
    friend GameVector operator+(const GameVector& v1, const GameVector& v2);

    friend GameVector operator-(const GameVector& v1, const GameVector& v2);

    friend GameVector operator-(const GameVector& v);

    template <typename T>
    friend GameVector operator* (const GameVector& v, const T scalar) { return GameVector(v.x * scalar, v.y * scalar); }

public:
    GameVector(const double x_, const double y_);
    void Normalize();
    void Rotate(const float angleDegree);

    double x;
    double y;
};