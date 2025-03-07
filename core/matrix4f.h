//
// Created by Geternitier on 2025/3/7.
//

#pragma once

namespace TempRenderer {

struct Matrix4f {
    float matrix[4][4] = {0};

    // 矩阵加法
    Matrix4f operator+(const Matrix4f& rhs) const {
        Matrix4f result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
            }
        }
        return result;
    }

    void operator+=(const Matrix4f& rhs) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] += rhs.matrix[i][j];
            }
        }
    }

    // 矩阵减法
    Matrix4f operator-(const Matrix4f& rhs) const {
        Matrix4f result;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                result.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
            }
        }
        return result;
    }

    void operator-=(const Matrix4f& rhs) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] -= rhs.matrix[i][j];
            }
        }
    }

    // 矩阵乘法
    Matrix4f operator*(const Matrix4f& rhs) const {
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

    void operator*=(const Matrix4f& rhs) {
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

    // 矩阵数乘（Matrix4f * float）
    Matrix4f operator*(float scalar) const {
        Matrix4f res;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                res.matrix[i][j] = matrix[i][j] * scalar;
            }
        }
        return res;
    }

    void operator*=(float scalar) {
        for (auto & i : matrix) {
            for (float & j : i) {
                j *= scalar;
            }
        }
    }

    // 矩阵数乘（float * Matrix4f）
    friend Matrix4f operator*(float scalar, Matrix4f matrix4f) {
        Matrix4f res;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                res.matrix[i][j] = matrix4f.matrix[i][j] * scalar;
            }
        }
        return res;
    }
};

}
