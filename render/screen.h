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
    Screen(int height, int width): height(height), width(width) {}
};

} // TempRenderer

