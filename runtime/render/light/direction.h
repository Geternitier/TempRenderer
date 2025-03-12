//
// Created by Geternitier on 2025/3/11.
//

#pragma once

#include "light.h"
#include "core/color.h"
#include "core/vector3f.h"

namespace TempRenderer {

class Direction: public Light {
    Color color;
    Vector3f direction;

public:
    Direction(Color c, Vector3f d): color(c), direction(d) {}
    void setLight(Color c) { color = c; }
    void setDirection(Vector3f v) { direction = v; }

    Color calculatePBR(const Vector3f& position,
                       const Vector3f& normal,
                       const Vector3f& look,
                       const Color& albedo,
                       const Material& material) override {
        direction.normalize();
        Vector3f halfway = -look - direction;
        halfway.normalize();
        const Vector3f& N = normal;
        const Vector3f& V = -look;
        const Vector3f& L = -direction;
        const Vector3f& H = halfway;

        float NdotV = std::max(N.dot(V), 0.0f);
        float NdotL = std::max(N.dot(L), 0.0f);
        float HdotV = std::max(H.dot(V), 0.0f);

        float D = Light::DistributionGGX(N, H, material.roughness);
        float G = Light::GeometrySmith(N, V, L, material.roughness);
        Vector3f v{0.04f};
        Vector3f F = Light::FresnelSchlick(HdotV, v + (color.toVector3f() - v) * material.metallic);

        Vector3f brdf = D * G * F / (4.f * NdotV * NdotL + 0.0001f);
        // 能量守恒项
        Vector3f kS = F;                     // 镜面反射比例
        Vector3f kD = (Vector3f(1.0f) - kS) * (1.0f - material.metallic); // 漫反射比例

        // 光照贡献
        Vector3f radiance = color.toVector3f() * NdotL;
        Color result = {(kD * albedo.toVector3f() / Math::PI + brdf) * radiance * 2};
        return result;
    }
};

}