//
// Created by Geternitier on 2025/3/8.
//

#pragma once

#include "core/vector3f.h"
#include "core/matrix4f.h"
#include "core/angle.h"

namespace TempRenderer {

/// 相机类
/// 相机坐标系: up为y轴, look为-z轴, y叉乘z得x轴
class Camera {
public:
    Camera(Vector3f pos, Vector3f look, Vector3f up): position(pos), look(look), up(up),
                                                      fov{}, near(1.f), far(1000.f) {}

    Vector3f getPosition() const { return position; }

    void setPosition(Vector3f pos) { position = pos; }
    void setLookUp(Vector3f l, Vector3f u) { look = l; up = u; }
    void setFov(Angle angle) { fov = angle; }
    void setNear(float f) { near = f; }
    void setFar(float f) { far = f; }

    void normalize() { look.normalize(); up.normalize(); }

    Matrix4f ViewMatrix() const;
    Matrix4f PerspectiveMatrix(float aspect) const;
    static Matrix4f OrthographicMatrix(float l, float b, float n, float r, float t, float f);

private:
    Vector3f position;
    Vector3f look;
    Vector3f up;

    Angle fov;
    float near;
    float far;
};

} // TempRenderer

