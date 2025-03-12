//
// Created by Geternitier on 2025/3/10.
//

#pragma once

#include "light.h"

#include "core/color.h"

namespace TempRenderer {

class Ambient: public Light {
    Color color;
    float intensity;

public:
    Ambient(Color c, float i): color(c), intensity(i) {}
    void setLight(Color c, float i) { color = c; intensity = i; }

    Color calculatePBR(const Vector3f& position,
                       const Vector3f& normal,
                       const Vector3f& look,
                       const Color& albedo,
                       const Material& material) override {
        return albedo * intensity;
    }
};

}