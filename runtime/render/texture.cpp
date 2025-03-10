//
// Created by Geternitier on 2025/3/10.
//

#include "texture.h"

namespace TempRenderer {

std::vector<Texture> Texture::textureAsset;
std::filesystem::path Texture::texturePath = Config::AssetPath() / "textures";

cv::Vec3b Texture::getColor(Vector2f uv) const {
    int y = (int) floor(uv.y * texture.rows);
    int x = (int) floor(uv.x * texture.cols);
    return texture.at<cv::Vec3b>(y, x);
}

Texture Texture::LoadTexture(std::string filename) {
    std::filesystem::path filepath = Texture::texturePath / filename;
    Texture t{cv::imread(filepath)};
    textureAsset.push_back(t);
    return t;
}

} // TempRenderer