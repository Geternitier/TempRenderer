//
// Created by Geternitier on 2025/3/8.
//

#pragma once
#include "core/vertex.h"

namespace TempRenderer {

struct Mesh {
    unsigned short vertexNum;
    unsigned short vertexIndexNum;
    Vertex* vertexData;
    unsigned short* vertexIndexData;
};

}
