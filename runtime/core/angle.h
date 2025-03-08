//
// Created by Geternitier on 2025/3/8.
//

#pragma once

#include "./math.h"
#include <cassert>

namespace TempRenderer {

class Radian {
    float rad;

public:
    Radian() = default;
    explicit Radian(float f) { rad = f; }
    Radian& operator=(float f) { rad = f; return *this; }
    float value() const { return rad; }
    void set(float f) { rad = f; }

};

class Degree {
    float degree;

public:
    Degree() = default;
    explicit Degree(float f) { degree = f; }
    Degree& operator=(float f) { degree = f; return *this; }
    float value() const { return degree; }
    void set(float f) { degree = f; }

};

enum AngleType {
    RADIAN, DEGREE
};

class Angle {
    float angle;
    AngleType type;
    Angle(float f, AngleType t): angle(f), type(t) {}

public:
    Angle(): angle(120), type(DEGREE) {};
    explicit Angle(Radian radian) { angle = radian.value(); type = RADIAN; }
    explicit Angle(Degree degree) { angle = degree.value(); type = DEGREE; }

    Angle& operator=(Radian radian) { angle = radian.value(); type = RADIAN; return *this; }
    Angle& operator=(Degree degree) { angle = degree.value(); type = DEGREE; return *this; }
    Angle& operator=(Angle rhs) { angle = rhs.angle; type = rhs.type; return *this; }

    Angle operator*(float rhs) const { return {angle * rhs, type}; }
    void operator*=(float rhs) { angle *= rhs; }
    Angle operator/(float rhs) const { assert(rhs != 0); return {angle / rhs, type}; }
    void operator/=(float rhs) { assert(rhs != 0); angle /= rhs; }

    float radian() {
        if (type == RADIAN) return angle;
        type = RADIAN;
        angle = angle / 180 * Math::PI;
        return angle;
    }

    float degree() {
        if (type == DEGREE) return angle;
        type = DEGREE;
        angle = angle * 180 / Math::PI;
        return angle;
    }

    static float tan(Angle a) { return std::tan(a.radian()); }
};

}