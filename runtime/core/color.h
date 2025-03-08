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
    Color() = default;
    Color(float r, float g, float b): r(r), g(g), b(b) {}
    explicit Color(Vector3f v): r(v.x), g(v.y), b(v.z) {}

    Color operator+(const Color& rhs) const { return {r + rhs.r, g + rhs.g, b + rhs.b}; }
    Color operator-(const Color& rhs) const { return {r - rhs.r, g - rhs.g, b - rhs.b}; }
    Color operator*(float f) const { return {r * f, g * f, b * f}; }
    friend Color operator*(float f, const Color& color) { return {color.r * f, color.g * f, color.b * f}; }

};

}

