#include <opencv2/opencv.hpp>

#include "render/renderer.h"
#include "render/texture.h"
#include "resource/cube.h"
#include "resource/sphere.h"
#include "util/application.h"

using namespace TempRenderer;

int main() {
    Application::Init();
    Texture::LoadImage("yuanshen.jpeg");
    Mesh mesh = createSphereMesh({0, 0, 0}, 1, {1, 1, 1});
    Application::AddMesh(mesh);

    Camera camera{{2, 0, 2}, {-1, 0, -1}, {0, 1, 0},
                  {60, DEGREE}, -0.1f, -50.f};
    Camera::setCurrentCamera(&camera);

    Application::Update();

    int key;
    while (true) {
        key = cv::waitKey();
        Vector3f pace{};
        switch (key) {
            case 'w':
                pace.z += 1.;
                break;
            case 'a':
                pace.x -= 1;
                break;
            case 's':
                pace.z -= 1;
                break;
            case 'd':
                pace.x += 1;
                break;
            case 'q':
                pace.y += 1;
                break;
            case 'e':
                pace.y -= 1;
                break;
            case 27:
                return 0;
        }
        camera.move(pace);
        Application::Update();
    }
}
