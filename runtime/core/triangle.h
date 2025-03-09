//
// Created by Geternitier on 2025/3/7.
//

#pragma once

#include "./math.h"
#include "vertex.h"

namespace TempRenderer {

struct Triangle {
    Vertex vertexes[3];

    static float CrossArea(const Vector3f& a, const Vector3f& b) {
        return a.cross(b).norm() / 2;
    }

    static float CrossArea2D(const Vector3f& a, const Vector3f& b) {
        return (a.x * b.y - a.y * b.x) / 2;
    }

    static Vector3f BaryCentric(const Vector3f& a, const Vector3f& b, const Vector3f& c, const Vector3f& p) {
        float s_abc = CrossArea(a - b, a - c);
        float s_bcp = CrossArea(c - b, p - b);
        float s_acp = CrossArea(a - c, p - c);

        float alpha = s_bcp / s_abc;
        float beta = s_acp / s_abc;
        return {alpha, beta, 1 - alpha - beta};
    }

    static Vector3f BaryCentric2D(const Vector3f& a, const Vector3f& b, const Vector3f& c, const Vector3f& p) {
        float s_abc = CrossArea2D(a - b, a - c);
        float s_bcp = CrossArea2D(c - b, p - b);
        float s_acp = CrossArea2D(a - c, p - c);

        float alpha = s_bcp / s_abc;
        float beta = s_acp / s_abc;
        return {alpha, beta, 1 - alpha - beta};
    }
};

}

