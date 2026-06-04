#pragma once

class GameVector
{
    friend GameVector operator+(const GameVector& v1, const GameVector& v2);
    friend GameVector operator-(const GameVector& v1, const GameVector& v2);
    friend GameVector operator-(const GameVector& v);

public:
    GameVector();
    GameVector(double x_, double y_);
    void Normalize();
    void Rotate(float angleDegree);

    template <typename T>
    GameVector operator* (const T scalar) { return GameVector(this->x * scalar, this->y * scalar); }

public:
    double x;
    double y;
};