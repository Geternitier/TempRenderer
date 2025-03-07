cmake_minimum_required(VERSION 3.21)
project(TempRenderer)

set(CMAKE_CXX_STANDARD 11)

set(OpenCV_DIR /opt/homebrew/Cellar/opencv/4.11.0_1/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(TempRenderer main.cpp
        core/color.h
        core/vertex.h
        core/vector3f.h
        render/renderer.cpp
        render/renderer.h
        render/screen.cpp
        render/screen.h
        asset/cube.h
        core/matrix4f.h
        core/transform.h
        core/triangle.h)
