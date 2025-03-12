//
// Created by Geternitier on 2025/3/7.
//

#ifndef NEW_CUBE_H
#define NEW_CUBE_H

#include <vector>

#include "core/vertex.h"
#include "core/vector3f.h"

namespace TempRenderer {

std::vector<Vertex> createCube() {
    std::vector<Vertex> cube;
    std::vector<Vector3f> positions = {
            // 前面
            {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5},
            {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
            // 后面
            {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5},
            {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}
    };

    std::vector<Color> colors = {
            {1,0,0}, {0,1,0},
            {0,0,1}, {1,1,0},
            {1,0,1}, {0,1,1},
            {0.5,0.5,0.5}, {1,1,1}
    };

    std::vector<int> indices = {
            0,1,2, 0,2,3, // 前
            4,5,6, 4,6,7, // 后
            0,3,7, 0,7,4, // 左
            1,2,6, 1,6,5, // 右
            0,1,5, 0,5,4, // 下
            3,2,6, 3,6,7  // 上
    };

    for (int i = 0; i < indices.size(); i += 3) {
        for (int j = 0; j < 3; j++) {
            Vertex v{};
            v.position = positions[indices[i + j]];
            v.color = colors[indices[i+j]];
            cube.push_back(v);
        }
    }

    return cube;
}

Mesh createCubeMesh() {
    unsigned int vertexNum = 8;
    unsigned int indicesSize = 36;

    std::vector<Vector3f> positions = {
            // 前面
            {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5},
            {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
            // 后面
            {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5},
            {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}
    };
    std::vector<Color> colors = {
            {1,0,0}, {0,1,0},
            {0,0,1}, {1,1,0},
            {1,0,1}, {0,1,1},
            {0.5,0.5,0.5}, {1,1,1}
    };
    std::vector<unsigned int> indices = {
            0,1,2, 0,2,3, // 前
            4,5,6, 4,6,7, // 后
            0,3,7, 0,7,4, // 左
            1,2,6, 1,6,5, // 右
            0,1,5, 0,5,4, // 下
            3,2,6, 3,6,7  // 上
    };

    std::vector<Vertex> cube(vertexNum);
    for (int i = 0; i < positions.size(); ++i) {
        cube[i] = Vertex{positions[i], colors[i]};
    }

    return {vertexNum, indicesSize, cube, indices};
}

Mesh createCubeTextureMesh() {
    unsigned int vertexNum = 8;
    unsigned int indicesSize = 36;

    std::vector<Vector3f> positions = {
            // 前面
            {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5},
            {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
            // 后面
            {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5},
            {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}
    };
    std::vector<Color> colors = {
            {1,0,0}, {0,1,0},
            {0,0,1}, {1,1,0},
            {1,0,1}, {0,1,1},
            {0.5,0.5,0.5}, {1,1,1}
    };
    std::vector<int> textureIndexes = {
            0, 0, 0, 0, -1, -1, -1, -1
    };
    std::vector<Vector2f> textureUVs = {
            {0, 0}, {1, 0},
            {1, 1}, {0, 1},
            {}, {}, {}, {}
    };
    std::vector<unsigned int> indices = {
            0,1,2, 0,2,3, // 前
            4,5,6, 4,6,7, // 后
            0,3,7, 0,7,4, // 左
            1,2,6, 1,6,5, // 右
            0,1,5, 0,5,4, // 下
            3,2,6, 3,6,7  // 上
    };

    std::vector<Vertex> cube(vertexNum);
    for (int i = 0; i < positions.size(); ++i) {
        cube[i] = Vertex{positions[i], colors[i], textureIndexes[i], textureUVs[i]};
    }

    return {vertexNum, indicesSize, cube, indices};
}

Mesh createCubeMaterialMesh() {
    unsigned int vertexNum = 24;
    unsigned int indicesSize = 36;

    std::vector<Vector3f> positions = {
            // 前面
            {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5},
            {-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5},
            // 后面
            {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5},
            {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5},
            // 上面
            {-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5},
            {-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5},
            // 下面
            {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5},
            {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5},
            // 左面
            {-0.5, -0.5, -0.5}, {-0.5, -0.5, 0.5},
            {-0.5, 0.5, -0.5}, {-0.5, 0.5, 0.5},
            // 右面
            {0.5, -0.5, -0.5}, {0.5, -0.5, 0.5},
            {0.5, 0.5, -0.5}, {0.5, 0.5, 0.5},
    };
    std::vector<Color> colors(vertexNum, {1, 1, 1});
    std::vector<int> textureIndexes(vertexNum, 0);
    std::vector<Vector2f> textureUVs = {
            // 前面
            {0, 0}, {1, 0},
            {0, 1}, {1, 1},

            // 后面
            {1, 0}, {0, 0},
            {1, 1}, {1, 0},

            // 上面
            {0, 0}, {1, 0},
            {0, 1}, {1, 1},

            // 下面
            {0, 0}, {1, 0},
            {0, 1}, {1, 1},

            // 左面
            {0, 0}, {1, 0},
            {0, 1}, {1, 1},

            // 右面
            {0, 0}, {1, 0},
            {0, 1}, {1, 1},
    };

    std::vector<Vector3f> normals = {
            {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1},

            {0, 0, -1}, {0, 0, -1}, {0, 0, -1}, {0, 0, -1},

            {0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0},

            {0, -1, 0}, {0, -1, 0}, {0, -1, 0}, {0, -1, 0},

            {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},

            {1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {1, 0, 0},
    };

    std::vector<unsigned int> indices = {
            0,1,2, 1,2,3, // 前
            4,5,6, 5,6,7, // 后
            8,9,10, 9,10,11, // 左
            12,13,14, 13,14,15, // 右
            16,17,18, 17,18,19, // 下
            20,21,22, 21,22,23  // 上
    };

    std::vector<Vertex> cube(vertexNum);
    Material material{0, 0.8, 0};
    for (int i = 0; i < positions.size(); ++i) {
        cube[i] = Vertex{positions[i], colors[i], normals[i], textureIndexes[i], textureUVs[i], material};
    }

    return {vertexNum, indicesSize, cube, indices};
}

}

#endif //NEW_CUBE_H
