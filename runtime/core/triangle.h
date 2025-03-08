//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include "vertex.h"

namespace TempRenderer {

struct Triangle {
    Vertex vertexes[3];

    static Vector3f Barycentric(Vector3f a, Vector3f b, Vector3f c, Vector3f p) {
        Vector3f v0 = b - a;
        Vector3f v1 = c - a;
        Vector3f v2 = p - a;

        float d00 = v0.dot(v0);
        float d01 = v0.dot(v1);
        float d11 = v1.dot(v1);
        float d20 = v2.dot(v0);
        float d21 = v2.dot(v1);
        float denom = d00 * d11 - d01 * d01;

        float v = (d11 * d20 - d01 * d21) / denom;
        float w = (d00 * d21 - d01 * d20) / denom;
        float u = 1 - v - w;

        return {u, v, w};
    }
};

}

