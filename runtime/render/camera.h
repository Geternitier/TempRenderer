//
// Created by Geternitier on 2025/3/8.
//

#pragma once

#include "core/vector3f.h"
#include "core/matrix4f.h"
#include "core/angle.h"

#include "util/screen.h"

namespace TempRenderer {

/// 相机类
/// 相机坐标系: up为y轴, look为-z轴, y叉乘z得x轴
class Camera {
    Vector3f position;
    Vector3f look;
    Vector3f up;

    Angle fov;
    float near;
    float far;

    Matrix4f viewMatrix{};
    Matrix4f projectionMatrix{};

    static Camera* currentCamera;

public:
    Camera(Vector3f pos, Vector3f look, Vector3f up): position(pos), look(look), up(up),
                                                      fov{60, DEGREE}, near(1.f), far(1000.f) {
        normalize();
        calViewMatrix();
        calPerspectiveMatrix(Screen::Aspect());
    }
    Camera(Vector3f pos, Vector3f look, Vector3f up,
           Angle fov, float near, float far): position(pos), look(look), up(up),
                                              fov(fov), near(near), far(far){
        normalize();
        calViewMatrix();
        calPerspectiveMatrix(Screen::Aspect());
    }

    Vector3f getPosition() const { return position; }
    Vector3f getLook() const { return look; }

    void move(Vector3f pace);
    void setPosition(Vector3f pos) { position = pos; calViewMatrix(); }
    void setLookUp(Vector3f l, Vector3f u) { look = l; up = u; normalize(); calViewMatrix(); }
    void setFov(Angle angle) { fov = angle; calPerspectiveMatrix(Screen::Aspect()); }
    void setNear(float n) { near = n; calPerspectiveMatrix(Screen::Aspect()); }
    void setFar(float f) { far = f; calPerspectiveMatrix(Screen::Aspect()); }

    void normalize() { look.normalize(); up.normalize(); }

    Matrix4f getViewMatrix() const { return viewMatrix; }
    Matrix4f getProjectionMatrix() const { return projectionMatrix; }

    void calViewMatrix();
    void calPerspectiveMatrix(float aspect);

    static Matrix4f OrthographicMatrix(float l, float b, float n, float r, float t, float f);

    static void setCurrentCamera(Camera* camera) { currentCamera = camera; }
    static Camera* getCurrentCamera() { return currentCamera; }

};

} // TempRenderer

