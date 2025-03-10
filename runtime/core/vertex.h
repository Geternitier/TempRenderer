//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include "color.h"
#include "vector2f.h"
#include "vector3f.h"

namespace TempRenderer{

struct Vertex {
    Vector3f position;
    Color color;
    int textureIndex;
    Vector2f uv;

    Vertex() = default;
    Vertex(Vector3f pos, Color c): position(pos), color(c), textureIndex(-1), uv{} {}
    Vertex(Vector3f pos, Color c, int texIndex, Vector2f texUV): position(pos), color(c),
                                                                 textureIndex(texIndex), uv(texUV) {}

    Vertex& operator=(const Vertex& rhs) {
        position = rhs.position; color = rhs.color;
        textureIndex = rhs.textureIndex; uv = rhs.uv; return *this; }
};

}

