//
// Created by Geternitier on 2025/3/7.
//

#pragma once

namespace TempRenderer {

class Screen {
public:
    int height;
    int width;
    Screen() { height = 600; width = 800; }
    Screen(int width, int height): width(width), height(height) {}

    void resize(int w, int h) { width = w; height = h; }
    float aspect() const { return width * 1.f / height; }
};

} // TempRenderer

