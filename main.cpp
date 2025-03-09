#include <opencv2/opencv.hpp>
#include <iostream>

#include "render/renderer.h"

#include "asset/cube.h"

using namespace TempRenderer;

int main() {
    int width = 1920;
    int height = 1080;
    Screen::Resize(width, height);

    Camera camera{{2, 0, 2}, {-1, 0, -1}, {0, 1, 0},
                  {60, DEGREE}, -0.1f, -50.f};
    Camera::setCurrentCamera(&camera);

    Renderer renderer{};
    renderer.render(createCubeMesh());

    renderer.show("Render");
    cv::waitKey();

    return 0;
}
