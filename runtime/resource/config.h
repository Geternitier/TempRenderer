//
// Created by Geternitier on 2025/3/9.
//

#pragma once

#include <filesystem>

namespace TempRenderer {

class Config {
    static std::filesystem::path root;
    static std::filesystem::path asset;

public:
    static std::filesystem::path RootPath() { return root; }
    static std::filesystem::path AssetPath() { return asset; }
};

} // TempRenderer

