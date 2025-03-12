//
// Created by Geternitier on 2025/3/11.
//

#pragma once

namespace TempRenderer {

class Material {
public:
    float metallic;
    float roughness;
    float ao;

    Material() = default;
    Material(float m, float r, float a): metallic(m), roughness(r), ao(a) {}
};

}