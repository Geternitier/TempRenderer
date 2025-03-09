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
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x};
}

std::ostream &operator<<(std::ostream &out, const Vector3f &v) {
    out << "[" << v.x << " " << v.y << " " << v.z << "]" << std::endl;
    return out;
}

}