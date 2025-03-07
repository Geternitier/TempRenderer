//
// Created by Geternitier on 2025/3/7.
//

#pragma once

namespace TempRenderer {

class Vector3f {
public:
    float x;
    float y;
    float z;
    Vector3f() = default;
    Vector3f(float x, float y, float z): x(x), y(y), z(z) {}
};

}

