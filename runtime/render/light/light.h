//
// Created by Geternitier on 2025/3/11.
//

#pragma once

#include "core/math.h"
#include "core/color.h"
#include "render/material.h"

namespace TempRenderer {

class Light {
public:
    virtual ~Light() = default;
    static std::vector<std::unique_ptr<Light>> lights;

    virtual Color calculatePBR(const Vector3f& position,
                               const Vector3f& normal,
                               const Vector3f& look,
                               const Color& albedo,
                               const Material& material) = 0;

    // 法线分布函数
    static float DistributionGGX(const Vector3f& N, const Vector3f& H, float roughness) {
        float a = roughness * roughness;
        float NdotH = std::max(N.dot(H), 0.f);
        float denom = NdotH * NdotH * (a - 1.f) + 1.f;
        return a / (Math::PI * denom * denom);
    }

    // 几何函数（Schlick-GGX）
    static float GeometrySchlickGGX(float NdotV, float roughness) {
        float r = (roughness + 1.f);
        float k = (r * r) / 8.f;
        return NdotV / (NdotV * (1.f - k) + k);
    }

    static float GeometrySmith(const Vector3f& N, const Vector3f& V, const Vector3f& L, float roughness) {
        float NdotV = std::max(N.dot(V), 0.f);
        float NdotL = std::max(N.dot(L), 0.f);
        float ggx1 = GeometrySchlickGGX(NdotV, roughness);
        float ggx2 = GeometrySchlickGGX(NdotL, roughness);
        return ggx1 * ggx2;
    }

    // 菲涅尔方程（Schlick近似）, cosTheta是表面法向量与观察方向v的点乘结果
    static Vector3f FresnelSchlick(float cosTheta, const Vector3f& F0) {
        return F0 + (Vector3f(1.f) - F0) * std::pow(1.f - cosTheta, 5.f);
    }
};

}