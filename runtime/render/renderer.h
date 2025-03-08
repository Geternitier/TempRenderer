//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include <opencv2/opencv.hpp>

#include "screen.h"

#include "core/math.h"
#include "core/vector3f.h"
#include "core/vertex.h"
#include "core/matrix4f.h"
#include "core/triangle.h"

#include "camera.h"

namespace TempRenderer {

class Renderer {
    Screen screen;
    Camera* camera;
    cv::Mat frameBuffer;
    cv::Mat depthBuffer;
    Color freshColor;

public:
    Renderer(int width, int height): screen(width, height), camera(nullptr), freshColor{0, 0, 1} {
        frameBuffer = cv::Mat{height, width, CV_8UC3, freshColor.toScalar()};
        depthBuffer = cv::Mat{height, width, CV_32F, -1.f};
    }
    void show(const std::string& name) const { cv::imshow(name, frameBuffer); }

    void setCamera(Camera* c) { camera = c; }
    void resizeScreen(int width, int height);

    void viewportTransform(Vector3f& coordinate) const;

    void clear();
    void rasterizeTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3);

};

}
