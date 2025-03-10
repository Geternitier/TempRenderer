//
// Created by Geternitier on 2025/3/10.
//

#pragma once

#include "vector3f.h"

namespace TempRenderer {

class Vector2f {
public:
    float x;
    float y;

    Vector2f() = default;
    Vector2f(float x, float y): x(x), y(y) {}
    explicit Vector2f(Vector3f v): x(v.x), y(v.y) {}

    Vector2f operator+(const Vector2f& rhs) const { return {x + rhs.x, y + rhs.y}; }
    Vector2f operator-(const Vector2f& rhs) const { return {x - rhs.x, y - rhs.y}; }
    Vector2f operator*(float rhs) const { return {x * rhs, y * rhs}; }
};

}


