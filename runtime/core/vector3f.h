//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include "./math.h"

namespace TempRenderer {

class Vector3f {
public:
    float x;
    float y;
    float z;
    Vector3f() = default;
    Vector3f(float x, float y, float z): x(x), y(y), z(z) {}

    Vector3f& operator=(Vector3f rhs) { x = rhs.x; y = rhs.y; z = rhs.z; return *this; }

    float norm() const { return Math::sqrt(x * x + y * y + z * z); }
    float normSquare() const { return x * x + y * y + z * z; }

    void normalize();

    float dot(const Vector3f& rhs) const;
    Vector3f cross(const Vector3f& rhs) const;

    Vector3f operator-() const { return {-x, -y, -z}; }
    Vector3f operator-(const Vector3f& rhs) const { return {x - rhs.x, y - rhs.y, z - rhs.z}; }
};

}

