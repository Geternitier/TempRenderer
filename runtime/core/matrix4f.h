//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include <iostream>

#include "vector3f.h"
#include "vector4f.h"

namespace TempRenderer {

struct Matrix4f {
    float matrix[4][4] = {0};

    void fill(float value);

    // 矩阵运算
    Matrix4f operator+(const Matrix4f& rhs) const;
    void operator+=(const Matrix4f& rhs);
    Matrix4f operator-(const Matrix4f& rhs) const;
    void operator-=(const Matrix4f& rhs);
    Matrix4f operator*(const Matrix4f& rhs) const;
    void operator*=(const Matrix4f& rhs);

    // 数乘
    Matrix4f operator*(float scalar) const;
    void operator*=(float scalar);
    friend Matrix4f operator*(float scalar, Matrix4f matrix4f);

    // 矩阵*向量
    Vector4f operator*(Vector4f rhs) const;
    Vector3f operator*(Vector3f rhs) const;

    // 输出
    friend std::ostream& operator<<(std::ostream& out, const Matrix4f& matrix);
};

}
