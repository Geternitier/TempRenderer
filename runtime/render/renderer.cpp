//
// Created by Geternitier on 2025/3/7.
//

#include "renderer.h"

namespace TempRenderer {

void Renderer::clear() {
    frameBuffer.setTo(freshColor.toScalar());
    depthBuffer.setTo(-1.f);
}

void Renderer::viewportTransform(TempRenderer::Vector3f &coordinate) const {
    coordinate.x = (coordinate.x + 1) * 0.5f * Screen::Width();
    coordinate.y = (coordinate.y + 1) * 0.5f * Screen::Height();
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
    int maxX = std::min(Screen::Width() - 1, (int)std::ceil(std::max({p1.x, p2.x, p3.x})));
    int minY = std::max(0, (int)std::floor(std::min({p1.y, p2.y, p3.y})));
    int maxY = std::min(Screen::Height() - 1, (int)std::ceil(std::max({p1.y, p2.y, p3.y})));

    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            Vector3f p(x + 0.5f, y + 0.5f, 0);
            Vector3f bary = Triangle::BaryCentric2D(p1, p2, p3, p);
            if (bary.x < 0 || bary.y < 0 || bary.z < 0) continue;
            float depth = p1.z * bary.x + p2.z * bary.y + p3.z * bary.z;
            if (depth > depthBuffer.at<float>(y, x)) {
                Color color = v1.color * bary.x + v2.color * bary.y + v3.color * bary.z;
                frameBuffer.at<cv::Vec3b>(y, x) = cv::Vec3b(color.b * 255, color.g * 255, color.r * 255);
                depthBuffer.at<float>(y, x) = depth;
            }
        }
    }
}

void Renderer::render(const Mesh &mesh) {
    clear();
    const Camera* camera = Camera::getCurrentCamera();
    if (camera == nullptr) {
        std::cout << "No Camera in the Scene, Renderer quit." << std::endl;
        return;
    }

    Matrix4f view = camera->getViewMatrix();
    Matrix4f perspective = camera->getProjectionMatrix();

    Vertex v1{}, v2{}, v3{};
    for (int i = 0; i < mesh.vertexIndexNum; ++i) {
        v1 = mesh.vertexData[mesh.vertexIndexData[i]];
        v2 = mesh.vertexData[mesh.vertexIndexData[i + 1]];
        v3 = mesh.vertexData[mesh.vertexIndexData[i + 2]];

        v1.position = view * v1.position;
        v2.position = view * v2.position;
        v3.position = view * v3.position;

        v1.position = perspective * v1.position;
        v2.position = perspective * v2.position;
        v3.position = perspective * v3.position;

        rasterizeTriangle(v1, v2, v3);
    }
}

}
