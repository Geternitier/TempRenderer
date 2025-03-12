//
// Created by Geternitier on 2025/3/10.
//

#include "application.h"

#include "render/light/direction.h"
#include "render/light/ambient.h"
#include "render/mesh.h"
#include "render/texture.h"
#include "resource/cube.h"
#include "resource/sphere.h"

namespace TempRenderer {

std::string Application::name = "TempRenderer";
std::vector<Mesh> Application::meshes;
Renderer Application::renderer{};

void Application::Init() {
    cv::namedWindow(name, cv::WINDOW_NORMAL);

    Light::lights.emplace_back(std::make_unique<Direction>(Color{1, 1, 1}, Vector3f{0, 0, -1}));
    Light::lights.emplace_back(std::make_unique<Ambient>(Color{1, 1, 1}, 0.3));

    Texture::LoadImage("yuanshen.jpeg");
    // Mesh mesh = createCubeMaterialMesh();
    Mesh mesh = createSphereMaterialMesh({0, 0, 0}, 1,
                                         {1, 1, 1}, 50, 50);
    Application::AddMesh(mesh);

    Camera camera{{2, 0, 2}, {-1, 0, -1}, {0, 1, 0},
                  {60, DEGREE}, -0.1f, -50.f};
    Camera::setCurrentCamera(&camera);
}

void Application::Update() {
    int key = cv::waitKey();
    Vector3f pace{};
    switch (key) {
        case 'w':
            pace.z += 0.5;
            break;
        case 'a':
            pace.x -= 0.5;
            break;
        case 's':
            pace.z -= 0.5;
            break;
        case 'd':
            pace.x += 0.5;
            break;
        case 'q':
            pace.y += 0.5;
            break;
        case 'e':
            pace.y -= 0.5;
            break;
        case 27:
            exit(0);
    }
    Camera::getCurrentCamera()->move(pace);
    for (Mesh& mesh: meshes) renderer.render(mesh);
    renderer.show(name);
}

} // TempRenderer