//
// Created by Geternitier on 2025/3/10.
//

#include "application.h"

namespace TempRenderer {

std::string Application::name = "TempRenderer";
std::vector<Mesh> Application::meshes;
Renderer Application::renderer{};

void Application::Init() {
    cv::namedWindow(name, cv::WINDOW_NORMAL);
}

void Application::Update() {
    for (Mesh& mesh: meshes) renderer.render(mesh);
    renderer.show(name);
}

} // TempRenderer