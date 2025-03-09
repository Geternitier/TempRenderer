//
// Created by Geternitier on 2025/3/7.
//

#pragma once

namespace TempRenderer {

class Screen {
    static int width;
    static int height;
    static float aspect;

    static void CalAspect() { aspect = width * 1.f / height; }
public:
    static int Width() { return width; }
    static int Height() { return height; }
    static void Resize(int w, int h) { width = w; height = h; CalAspect(); }
    static float Aspect() { return aspect; }

};

} // TempRenderer

