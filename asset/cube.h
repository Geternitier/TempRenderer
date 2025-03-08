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
            {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5},
            // 后面
            {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}
    };

    std::vector<Color> colors = {
            {1,0,0}, {0,1,0}, {0,0,1}, {1,1,0},
            {1,0,1}, {0,1,1}, {0.5,0.5,0.5}, {1,1,1}
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

}

#endif //NEW_CUBE_H
