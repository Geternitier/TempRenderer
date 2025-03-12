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
    Color(Vector3f v): r(v.x), g(v.y), b(v.z) {}
    Color(cv::Vec3b v): r(v[2] * 1.f / 255), g(v[1] * 1.f / 255), b(v[0] * 1.f / 255) {}

    Color operator+(const Color& rhs) const { return {r + rhs.r, g + rhs.g, b + rhs.b}; }
    Color operator-(const Color& rhs) const { return {r - rhs.r, g - rhs.g, b - rhs.b}; }
    Color operator*(float f) const { return {r * f, g * f, b * f}; }
    friend Color operator*(float f, const Color& color) { return {color.r * f, color.g * f, color.b * f}; }

    void operator+=(Color rhs) { r += rhs.r; g += rhs.g; b += rhs.b; }
    Color& operator=(const Color& rhs) = default;

    cv::Scalar toScalar() const { return {b * 255, g * 255, r * 255}; }
    cv::Vec3b toVec3b() const { return cv::Vec3b(b * 255, g * 255, r * 255); }
    Vector3f toVector3f() const { return {r, g, b}; }


    friend std::ostream& operator<<(std::ostream& out, const Color& c) {
        out << '[' << c.r << ", " << c.g << ", " << c.b << ']' << std::endl;
        return out;
    }
};

}

