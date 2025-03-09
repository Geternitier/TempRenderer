//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>

#include "core/math.h"
#include "core/vector3f.h"
#include "core/vertex.h"
#include "core/matrix4f.h"
#include "core/triangle.h"

#include "mesh.h"
#include "camera.h"
#include "util/screen.h"

namespace TempRenderer {

class Renderer {
    cv::Mat frameBuffer;
    cv::Mat depthBuffer;
    Color freshColor;

public:
    Renderer(): freshColor{0, 0, 1} {
        frameBuffer = cv::Mat{Screen::Height(), Screen::Width(), CV_8UC3, freshColor.toScalar()};
        depthBuffer = cv::Mat{Screen::Height(), Screen::Width(), CV_32F, -1.f};
    }
    void show(const std::string& name) const { cv::imshow(name, frameBuffer); }

    void viewportTransform(Vector3f& coordinate) const;

    void clear();
    void rasterizeTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3);
    void render(const Mesh& mesh);

};

}
