//
// Created by Geternitier on 2025/3/8.
//

#include "camera.h"

namespace TempRenderer {

Camera* Camera::currentCamera = nullptr;

void Camera::calViewMatrix() {
    Vector3f z = - look;
    const Vector3f& y = up;
    Vector3f x = y.cross(z);

    viewMatrix.fill(0);
    viewMatrix.matrix[0][0] = x.x;
    viewMatrix.matrix[0][1] = x.y;
    viewMatrix.matrix[0][2] = x.z;
    viewMatrix.matrix[0][3] = -x.dot(position);

    viewMatrix.matrix[1][0] = y.x;
    viewMatrix.matrix[1][1] = y.y;
    viewMatrix.matrix[1][2] = y.z;
    viewMatrix.matrix[1][3] = -y.dot(position);

    viewMatrix.matrix[2][0] = z.x;
    viewMatrix.matrix[2][1] = z.y;
    viewMatrix.matrix[2][2] = z.z;
    viewMatrix.matrix[2][3] = -z.dot(position);

    viewMatrix.matrix[3][3] = 1;
}

void Camera::calPerspectiveMatrix(float aspect) {
    projectionMatrix.fill(0);
    float tanHalfFov = Angle::tan(fov / 2);
    projectionMatrix.matrix[0][0] = -1 / (aspect * tanHalfFov);
    projectionMatrix.matrix[1][1] = 1 / tanHalfFov;
    projectionMatrix.matrix[2][2] = (near + far) / (near - far);
    projectionMatrix.matrix[2][3] = 2 * far * near / (far - near);
    projectionMatrix.matrix[3][2] = 1;
}

Matrix4f Camera::OrthographicMatrix(float l, float b, float n, float r, float t, float f) {
    Matrix4f orthographic{};
    orthographic.matrix[0][0] = 2 / (r - l);
    orthographic.matrix[1][1] = 2 / (t - b);
    orthographic.matrix[2][2] = 2 / (n - f);
    orthographic.matrix[0][3] = (l + r) / (l - r);
    orthographic.matrix[1][3] = (b + t) / (b - t);
    orthographic.matrix[2][3] = (f + n) / (f - n);
    orthographic.matrix[3][3] = 1;

    return orthographic;
}

} // TempRenderer