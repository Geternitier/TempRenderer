//
// Created by Geternitier on 2025/3/8.
//

#pragma once

#include "vector3f.h"

namespace TempRenderer {

class Vector4f {
public:
    float x;
    float y;
    float z;
    float w;
    Vector4f(): x(0), y(0), z(0), w(1) {}
    Vector4f(float x, float y, float z): x(x), y(y), z(z), w(1) {}
    Vector4f(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {}
    explicit Vector4f(Vector3f v): x(v.x), y(v.y), z(v.z), w(1) {}

    Vector3f toVector3f() const { return {x / w, y / w, z / w}; }
};

}
