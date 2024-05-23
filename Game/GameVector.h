#pragma once

class GameVector
{
    friend GameVector operator+(const GameVector& v1, const GameVector& v2);
    friend GameVector operator-(const GameVector& v1, const GameVector& v2);

public:
    GameVector(float x_, float y_);
    void Normalize();
    void Rotate(float angleDegree);

private:
    float x;
    float y;
};