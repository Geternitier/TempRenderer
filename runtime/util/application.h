//
// Created by Geternitier on 2025/3/10.
//

#pragma once

#include <iostream>

#include <opencv2/opencv.hpp>
#include <utility>

#include "render/renderer.h"
#include "render/mesh.h"

namespace TempRenderer {

class Application {
    static std::string name;
    static Renderer renderer;
    static std::vector<Mesh> meshes;

public:
    static void Init();
    static void Init(std::string s) { name = std::move(s); Init(); }
    static void Run();
    static void Update();
    static void AddMesh(Mesh& mesh) { meshes.push_back(mesh); }

};

} // TempRenderer

