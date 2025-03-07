//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include "color.h"
#include "vector3f.h"

namespace TempRenderer{

struct Vertex {
    Color color;
    Vector3f coordinate;
    Vector3f normal;
};

}

