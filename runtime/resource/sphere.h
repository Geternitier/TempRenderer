//
// Created by Geternitier on 2025/3/10.
//

#pragma once

#include "render/mesh.h"

namespace TempRenderer{

Mesh createSphereMesh(Vector3f center, float radius, Color color,
                      unsigned int slices = 30, unsigned int stacks = 30) {
    Mesh mesh;
    std::vector<Vertex>& vertices = mesh.vertexData;
    std::vector<unsigned int>& indices = mesh.vertexIndexData;

    // 顶点
    vertices.push_back({{center.x, center.y, center.z + radius}, color});
    vertices.push_back({{center.x, center.y, center.z - radius}, color});

    for (unsigned int i = 1; i < stacks; ++i) {
        float theta = i * Math::PI / stacks;
        float sinTheta = std::sin(theta);
        float cosTheta = std::cos(theta);

        for (unsigned int j = 0; j < slices; ++j) {
            float phi = j * 2 * Math::PI / slices;
            float sinPhi = std::sin(phi);
            float cosPhi = std::cos(phi);

            vertices.push_back({{center.x + radius * sinTheta * cosPhi,
                                 center.y + radius * sinTheta * sinPhi,
                                 center.z + radius * cosTheta}, color});
        }
    }

    // 生成索引
    const unsigned int topIndex = 0;
    const unsigned int bottomIndex = 1 + (stacks - 1) * slices;

    // 顶部盖子
    for (unsigned int j = 0; j < slices; ++j) {
        indices.push_back(topIndex);
        indices.push_back(1 + j);
        indices.push_back(1 + (j + 1) % slices);
    }

    // 中间层四边形
    for (unsigned int i = 0; i < stacks - 2; ++i) {
        unsigned int layerStart = 1 + i * slices;
        unsigned int nextLayerStart = 1 + (i + 1) * slices;

        for (unsigned int j = 0; j < slices; ++j) {
            unsigned int jNext = (j + 1) % slices;

            unsigned int a = layerStart + j;
            unsigned int b = layerStart + jNext;
            unsigned int c = nextLayerStart + jNext;
            unsigned int d = nextLayerStart + j;

            indices.push_back(a);
            indices.push_back(b);
            indices.push_back(c);

            indices.push_back(a);
            indices.push_back(c);
            indices.push_back(d);
        }
    }

    // 底部盖子
    unsigned int lastLayerStart = 1 + (stacks - 2) * slices;
    for (unsigned int j = 0; j < slices; ++j) {
        indices.push_back(bottomIndex);
        indices.push_back(lastLayerStart + (j + 1) % slices);
        indices.push_back(lastLayerStart + j);
    }

    // 设置顶点和索引数量
    mesh.vertexNum = vertices.size();
    mesh.vertexIndexNum = indices.size();

    return mesh;
}

Mesh createSphereMaterialMesh(Vector3f center, float radius, Color color,
                          unsigned int slices = 30, unsigned int stacks = 30) {
    Mesh mesh;
    std::vector<Vertex>& vertices = mesh.vertexData;
    std::vector<unsigned int>& indices = mesh.vertexIndexData;

    // 顶点
    vertices.push_back({{center.x, center.y, center.z + radius}, color, {0, 0, 1}, {0.5, 0.8, 0}});
    vertices.push_back({{center.x, center.y, center.z - radius}, color, {0, 0, 1}, {0.5, 0.8, 0}});

    for (unsigned int i = 1; i < stacks; ++i) {
        float theta = i * Math::PI / stacks;
        float sinTheta = std::sin(theta);
        float cosTheta = std::cos(theta);

        for (unsigned int j = 0; j < slices; ++j) {
            float phi = j * 2 * Math::PI / slices;
            float sinPhi = std::sin(phi);
            float cosPhi = std::cos(phi);

            vertices.push_back({{center.x + radius * sinTheta * cosPhi,
                                 center.y + radius * sinTheta * sinPhi,
                                 center.z + radius * cosTheta}, color,
                                {sinTheta * cosPhi, sinTheta * sinPhi, cosTheta},
                                {0.5, 0.8, 0}});
        }
    }

    // 生成索引
    const unsigned int topIndex = 0;
    const unsigned int bottomIndex = 1 + (stacks - 1) * slices;

    // 顶部盖子
    for (unsigned int j = 0; j < slices; ++j) {
        indices.push_back(topIndex);
        indices.push_back(1 + j);
        indices.push_back(1 + (j + 1) % slices);
    }

    // 中间层四边形
    for (unsigned int i = 0; i < stacks - 2; ++i) {
        unsigned int layerStart = 1 + i * slices;
        unsigned int nextLayerStart = 1 + (i + 1) * slices;

        for (unsigned int j = 0; j < slices; ++j) {
            unsigned int jNext = (j + 1) % slices;

            unsigned int a = layerStart + j;
            unsigned int b = layerStart + jNext;
            unsigned int c = nextLayerStart + jNext;
            unsigned int d = nextLayerStart + j;

            indices.push_back(a);
            indices.push_back(b);
            indices.push_back(c);

            indices.push_back(a);
            indices.push_back(c);
            indices.push_back(d);
        }
    }

    // 底部盖子
    unsigned int lastLayerStart = 1 + (stacks - 2) * slices;
    for (unsigned int j = 0; j < slices; ++j) {
        indices.push_back(bottomIndex);
        indices.push_back(lastLayerStart + (j + 1) % slices);
        indices.push_back(lastLayerStart + j);
    }

    // 设置顶点和索引数量
    mesh.vertexNum = vertices.size();
    mesh.vertexIndexNum = indices.size();

    return mesh;
}

}
