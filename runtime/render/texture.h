//
// Created by Geternitier on 2025/3/10.
//

#pragma once

#include <filesystem>
#include <opencv2/opencv.hpp>
#include <vector>
#include <utility>

#include "core/vector2f.h"
#include "core/color.h"
#include "resource/config.h"

namespace TempRenderer {

class Texture {
    cv::Mat texture;

    static std::vector<Texture> textureAsset;
    static std::filesystem::path imagePath;

    Texture(cv::Mat texture): texture(std::move(texture)) {}
public:
    cv::Vec3b getColor(Vector2f uv) const;

    static Texture LoadImage(const std::string& filename);
    static const Texture& GetTexture(int index) { return textureAsset[index]; }

};

} // TempRenderer

