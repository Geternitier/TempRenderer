//
// Created by Geternitier on 2025/3/7.
//

#include "renderer.h"

namespace TempRenderer {

void Renderer::resizeScreen(int width, int height) {
    screen.resize(width, height);
    frameBuffer = cv::Mat::zeros(height, width, CV_8UC3);
    depthBuffer = cv::Mat::ones(height, width, CV_32F);
}

void Renderer::clear() {
    frameBuffer.setTo(cv::Scalar(0, 0, 0));
    depthBuffer.setTo(1.f);
}

void Renderer::viewportTransform(TempRenderer::Vector3f &coordinate) const {
    coordinate.x = (coordinate.x + 1) * 0.5f * screen.width;
    coordinate.y = (coordinate.y + 1) * 0.5f * screen.width;
}

void Renderer::rasterizeTriangle(const Vertex &v1, const Vertex &v2, const Vertex &v3) {
    Vector3f p1 = v1.position;
    Vector3f p2 = v2.position;
    Vector3f p3 = v3.position;

    viewportTransform(p1);
    viewportTransform(p2);
    viewportTransform(p3);

    // 计算包围盒
    int minX = std::max(0, (int)std::floor(std::min({p1.x, p2.x, p3.x})));
    int maxX = std::min(screen.width - 1, (int)std::ceil(std::max({p1.x, p2.x, p3.x})));
    int minY = std::max(0, (int)std::floor(std::min({p1.y, p2.y, p3.y})));
    int maxY = std::min(screen.height - 1, (int)std::ceil(std::max({p1.y, p2.y, p3.y})));

    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            Vector3f p(x + 0.5f, y + 0.5f, 0);
            Vector3f bary = Triangle::Barycentric(p1, p2, p3, p);
            if (bary.x < 0 || bary.y < 0 || bary.z < 0) continue;
            float depth = p1.z * bary.x + p2.z * bary.y + p3.z + bary.z;
            if (depth < depthBuffer.at<float>(y, x)) {
                Color color = v1.color * bary.x + v2.color * bary.y + v3.color * bary.z;
                frameBuffer.at<cv::Vec3b>(y, x) = cv::Vec3b(color.b * 255, color.g * 255, color.r * 255);
                depthBuffer.at<float>(y, x) = depth;
            }
        }
    }
}

}
