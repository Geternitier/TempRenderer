//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include <opencv2/opencv.hpp>

#include "screen.h"
#include "../core/vector3f.h"
#include "../core/vertex.h"
#include "../core/matrix4f.h"

namespace TempRenderer {

class Renderer {
    Screen screen;
    cv::Mat frameBuffer;
    cv::Mat depthBuffer;

public:
    Renderer(int height, int width): screen(height, width) {
        frameBuffer = cv::Mat::zeros(height, width, CV_8UC3);
        depthBuffer = cv::Mat::ones(height, width, CV_32F);
    }

    void clear() {
        frameBuffer.setTo(cv::Scalar(0, 0, 0));
        depthBuffer.setTo(1.f);
    }

    void viewportTransform(Vector3f& coordinate) const {
        coordinate.x = (coordinate.x + 1) * 0.5f * screen.width;
        coordinate.y = (coordinate.y + 1) * 0.5f * screen.width;
    }

    void rasterize(const Vertex& v1, const Vertex& v2, const Vertex& v3) {

    }
};

}
