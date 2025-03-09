//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include "color.h"
#include "vector3f.h"

namespace TempRenderer{

struct Vertex {
    Vector3f position;
    Color color;

    Vertex& operator=(const Vertex& rhs) { position = rhs.position; color = rhs.color; return *this; }
};

}

