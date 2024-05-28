#pragma once

class GameVector
{
    friend GameVector operator+(const GameVector& v1, const GameVector& v2);
    friend GameVector operator-(const GameVector& v1, const GameVector& v2);
    friend GameVector operator-(const GameVector& v);

public:
    GameVector();
    // GameVector(const GameVector& v);
    GameVector(double x_, double y_);
    void Normalize();
    void Rotate(float angleDegree);

public:
    double x;
    double y;
};