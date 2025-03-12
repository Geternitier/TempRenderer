//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include "color.h"
#include "vector2f.h"
#include "vector3f.h"

#include "render/material.h"

namespace TempRenderer{

struct Vertex {
    Vector3f position;
    Color color;
    Vector3f normal;
    Vector2f uv;
    int textureIndex;
    Material material;

    Vertex() = default;
    Vertex(Vector3f pos, Color c): position(pos), color(c), textureIndex(-1), uv{}, material{} {}
    Vertex(Vector3f pos, Color c, Material m): position(pos), color(c), textureIndex(-1), uv{}, material{m} {}
    Vertex(Vector3f pos, Color c, int texIndex, Vector2f texUV): position(pos), color(c),
                                                                 textureIndex(texIndex), uv(texUV),
                                                                 material{}{}
    Vertex(Vector3f pos, Color c, int texIndex, Vector2f texUV, Material material):
    position(pos), color(c), textureIndex(texIndex), uv(texUV), material(material) {}
    Vertex(Vector3f pos, Color c, Vector3f normal, int texIndex, Vector2f texUV, Material material):
            position(pos), color(c),normal(normal), textureIndex(texIndex), uv(texUV), material(material) {}
    Vertex(Vector3f pos, Color c, Vector3f normal, Material material):
            position(pos), color(c), normal(normal), textureIndex(-1), uv{}, material(material) {}

    Vertex& operator=(const Vertex& rhs) {
        position = rhs.position; color = rhs.color; normal = rhs.normal;
        textureIndex = rhs.textureIndex; uv = rhs.uv; material = rhs.material; return *this; }
};

}

