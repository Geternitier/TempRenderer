//
// Created by Geternitier on 2025/3/8.
//

#include "vector3f.h"

namespace TempRenderer {

void Vector3f::normalize() {
    float norm_ = norm();
    x /= norm_;
    y /= norm_;
    z /= norm_;
}

    float Vector3f::dot(const Vector3f &rhs) const {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    Vector3f Vector3f::cross(const Vector3f &rhs) const {
        return {y * rhs.z - z * rhs.y,
                (-z) * rhs.x - x * rhs.z,
                y * rhs.x - x * rhs.y};
    }

}