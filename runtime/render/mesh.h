//
// Created by Geternitier on 2025/3/8.
//

#pragma once

#include <fstream>
#include <filesystem>
#include <iostream>
#include <utility>
#include <vector>

#include "core/vertex.h"
#include "resource/config.h"

namespace TempRenderer {

struct Mesh {
    unsigned int vertexNum;
    unsigned int vertexIndexNum;
    std::vector<Vertex> vertexData;
    std::vector<unsigned int> vertexIndexData;
    static std::filesystem::path meshSavePath;

    Mesh() = default;
    Mesh(unsigned int vertexNum,
         unsigned int vertexIndexNum,
         std::vector<Vertex> vertexData,
         std::vector<unsigned int> vertexIndexData): vertexNum(vertexNum),
                                           vertexIndexNum(vertexIndexNum),
                                           vertexData(std::move(vertexData)),
                                           vertexIndexData(std::move(vertexIndexData)) {}

    void save(std::string filename) const {
        std::filesystem::path filepath = meshSavePath / filename;
        std::ofstream file(filepath, std::ios::binary);
        if (!file.is_open()) {
            std::cout << "无法打开文件进行写入: " << filepath << std::endl;
            return;
        }

        // 写入文件头 "mesh"
        const char header[] = {'m', 'e', 's', 'h'};
        file.write(header, 4);

        // 写入顶点数和索引数
        file.write(reinterpret_cast<const char*>(&vertexNum), sizeof(unsigned int));
        file.write(reinterpret_cast<const char*>(&vertexIndexNum), sizeof(unsigned int));

        // 写入顶点数据（每个顶点8个float）
        for (const auto& vertex : vertexData) {
            // 写入位置
            file.write(reinterpret_cast<const char*>(&vertex.position.x), sizeof(float));
            file.write(reinterpret_cast<const char*>(&vertex.position.y), sizeof(float));
            file.write(reinterpret_cast<const char*>(&vertex.position.z), sizeof(float));
            // 写入颜色
            file.write(reinterpret_cast<const char*>(&vertex.color.r), sizeof(float));
            file.write(reinterpret_cast<const char*>(&vertex.color.g), sizeof(float));
            file.write(reinterpret_cast<const char*>(&vertex.color.b), sizeof(float));
            // 写入纹理与坐标
            file.write(reinterpret_cast<const char*>(&vertex.textureIndex), sizeof(int));
            file.write(reinterpret_cast<const char*>(&vertex.uv.x), sizeof(float));
            file.write(reinterpret_cast<const char*>(&vertex.uv.y), sizeof(float));
        }

        // 写入索引数据
        file.write(reinterpret_cast<const char*>(vertexIndexData.data()),
                   vertexIndexData.size() * sizeof(unsigned int));
    }

    static Mesh Load(const std::string& filename) {
        std::filesystem::path filepath = meshSavePath / filename;
        std::ifstream file(filepath, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("无法打开文件: " + filepath.string());
        }

        // 验证文件头
        char header[4];
        file.read(header, 4);
        if (std::strncmp(header, "mesh", 4) != 0) {
            throw std::runtime_error("无效的文件格式");
        }

        // 读取顶点数和索引数
        unsigned int vertexNum, vertexIndexNum;
        file.read(reinterpret_cast<char*>(&vertexNum), sizeof(unsigned int));
        file.read(reinterpret_cast<char*>(&vertexIndexNum), sizeof(unsigned int));

        // 读取顶点数据
        std::vector<Vertex> vertices;
        vertices.reserve(vertexNum);
        for (unsigned int i = 0; i < vertexNum; ++i) {
            float x, y, z, r, g, b, u, v;
            int index;
            file.read(reinterpret_cast<char*>(&x), sizeof(float));
            file.read(reinterpret_cast<char*>(&y), sizeof(float));
            file.read(reinterpret_cast<char*>(&z), sizeof(float));
            file.read(reinterpret_cast<char*>(&r), sizeof(float));
            file.read(reinterpret_cast<char*>(&g), sizeof(float));
            file.read(reinterpret_cast<char*>(&b), sizeof(float));
            file.read(reinterpret_cast<char*>(&index), sizeof(int));
            file.read(reinterpret_cast<char*>(&u), sizeof(float));
            file.read(reinterpret_cast<char*>(&v), sizeof(float));
            vertices.emplace_back(Vertex{{x, y, z}, {r, g, b}, index, {u, v}});
        }

        // 读取索引数据
        std::vector<unsigned int> indices(vertexIndexNum);
        file.read(reinterpret_cast<char*>(indices.data()),
                  vertexIndexNum * sizeof(unsigned int));

        // 检查读取完整性
        if (!file.good()) {
            std::cout <<"文件读取错误或数据不完整" << std::endl;
        }

        return {vertexNum, vertexIndexNum, std::move(vertices), std::move(indices)};
    }
};

}
