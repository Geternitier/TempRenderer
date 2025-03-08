//
// Created by Geternitier on 2025/3/8.
//

#include "matrix4f.h"

namespace TempRenderer {

Matrix4f Matrix4f::operator+(const Matrix4f &rhs) const {
    Matrix4f result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return result;
}

void Matrix4f::operator+=(const Matrix4f &rhs)  {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] += rhs.matrix[i][j];
        }
    }
}

Matrix4f Matrix4f::operator-(const Matrix4f &rhs) const {
    Matrix4f result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
        }
    }
    return result;
}

void Matrix4f::operator-=(const Matrix4f &rhs) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] -= rhs.matrix[i][j];
        }
    }
}

Matrix4f Matrix4f::operator*(const Matrix4f &rhs) const {
    Matrix4f result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }
    return result;
}

void Matrix4f::operator*=(const Matrix4f &rhs) {
    Matrix4f result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 4; ++k) {
                result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = result.matrix[i][j];
        }
    }
}

Matrix4f Matrix4f::operator*(float scalar) const {
    Matrix4f res;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            res.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return res;
}

void Matrix4f::operator*=(float scalar) {
    for (auto & i : matrix) {
        for (float & j : i) {
            j *= scalar;
        }
    }
}

Matrix4f operator*(float scalar, Matrix4f matrix4f) {
    Matrix4f res;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            res.matrix[i][j] = matrix4f.matrix[i][j] * scalar;
        }
    }
    return res;
}

Vector4f Matrix4f::operator*(Vector4f rhs) const {
    return {matrix[0][0] * rhs.x + matrix[0][1] * rhs.y + matrix[0][2] * rhs.z + matrix[0][3] * rhs.w,
            matrix[1][0] * rhs.x + matrix[1][1] * rhs.y + matrix[1][2] * rhs.z + matrix[1][3] * rhs.w,
            matrix[2][0] * rhs.x + matrix[2][1] * rhs.y + matrix[2][2] * rhs.z + matrix[2][3] * rhs.w,
            matrix[3][0] * rhs.x + matrix[3][1] * rhs.y + matrix[2][2] * rhs.z + matrix[3][3] * rhs.w};
}

Vector3f Matrix4f::operator*(Vector3f rhs) const {
    return (*this * Vector4f{rhs}).toVector3f();
}


}