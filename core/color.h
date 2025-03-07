//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include <opencv2/opencv.hpp>

#include "vector3f.h"

namespace TempRenderer {

struct Color {
    float r;
    float g;
    float b;
    float a;
    Color() = default;
    Color(float r, float g, float b): r(r), g(g), b(b), a(1) {}
    Color(Vector3f vector3): r(vector3.x), g(vector3.y), b(vector3.z), a(1) {}
    Color(float r, float g, float b, float a): r(r), g(g), b(b), a(a) {}
};

}

