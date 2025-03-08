#include <opencv2/opencv.hpp>
#include <iostream>

#include "render/renderer.h"

#include "asset/cube.h"

using namespace TempRenderer;

int main() {
    Renderer renderer{800, 600};
    auto cube = createCube();
    Camera camera{{0, 0, 3}, {0, 0, -1}, {0, 1, 0}};
    camera.normalize();
    renderer.setCamera(&camera);
    renderer.clear();

    Matrix4f view = camera.ViewMatrix();
    std::cout << view;
    Matrix4f perspective = camera.PerspectiveMatrix(800. / 600);
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
