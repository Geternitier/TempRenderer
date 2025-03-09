#include <opencv2/opencv.hpp>
#include <iostream>

#include "render/renderer.h"

#include "asset/cube.h"

using namespace TempRenderer;

int main() {
    int width = 1920;
    int height = 1080;
    Renderer renderer{width, height};
    auto cube = createCube();
    Camera camera{{2, 0, 2}, {-1, 0, -1}, {0, 1, 0}};
    camera.setFov({60, DEGREE});
    camera.setNear(-0.1f);
    camera.setFar(-50.f);
    camera.normalize();
    renderer.setCamera(&camera);

    renderer.clear();

    Matrix4f view = camera.ViewMatrix();
    std::cout << view;
    Matrix4f perspective = camera.PerspectiveMatrix(width * 1.f / height);
    std::cout << perspective;

    for (int i = 0; i < cube.size(); i += 3) {
        Vertex v1 = cube[i];
        Vertex v2 = cube[i + 1];
        Vertex v3 = cube[i + 2];

        v1.position = view * v1.position;
        v2.position = view * v2.position;
        v3.position = view * v3.position;

        v1.position = perspective * v1.position;
        v2.position = perspective * v2.position;
        v3.position = perspective * v3.position;

        renderer.rasterizeTriangle(v1, v2, v3);
    }

    renderer.show("Render");
    cv::waitKey();

    return 0;
}
