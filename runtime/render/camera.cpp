//
// Created by Geternitier on 2025/3/8.
//

#include "camera.h"

namespace TempRenderer {
    Matrix4f Camera::ViewMatrix() const {
        Vector3f z = - look;
        const Vector3f& y = up;
        Vector3f x = y.cross(z);

        Matrix4f view{};
        view.matrix[0][0] = x.x;
        view.matrix[0][1] = x.y;
        view.matrix[0][2] = x.z;
        view.matrix[0][3] = -x.dot(position);

        view.matrix[1][0] = y.x;
        view.matrix[1][1] = y.y;
        view.matrix[1][2] = y.z;
        view.matrix[1][3] = -y.dot(position);

        view.matrix[2][0] = z.x;
        view.matrix[2][1] = z.y;
        view.matrix[2][2] = z.z;
        view.matrix[2][3] = -z.dot(position);

        view.matrix[3][3] = 1;
        return view;
    }

    Matrix4f Camera::PerspectiveMatrix(float aspect) const {
        Matrix4f perspective{};
        float tanHalfFov = Angle::tan(fov / 2);
        perspective.matrix[0][0] = -1 / (aspect * tanHalfFov);
        perspective.matrix[1][1] = 1 / tanHalfFov;
        perspective.matrix[2][2] = (near + far) / (near - far);
        perspective.matrix[2][3] = 2 * far * near / (far - near);
        perspective.matrix[3][2] = 1;

        return perspective;
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