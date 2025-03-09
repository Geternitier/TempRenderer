cmake_minimum_required(VERSION 3.21)
project(TempRenderer)

set(CMAKE_CXX_STANDARD 11)

include_directories(runtime)

set(OpenCV_DIR /opt/homebrew/Cellar/opencv/4.11.0_1/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(TempRenderer main.cpp
        runtime/core/color.h
        runtime/core/vertex.h
        runtime/core/vector3f.h
        runtime/render/renderer.cpp
        runtime/render/renderer.h
        runtime/util/screen.cpp
        runtime/util/screen.h
        asset/cube.h
        runtime/core/matrix4f.h
        runtime/core/transform.h
        runtime/core/triangle.h
        runtime/render/mesh.h
        runtime/render/camera.cpp
        runtime/render/camera.h
        runtime/core/vector3f.cpp
        runtime/core/math.cpp
        runtime/core/math.h
        runtime/core/angle.h
        runtime/core/vector4f.h
        runtime/core/matrix4f.cpp
        scene/index.cpp
        scene/index.h)

target_link_libraries(TempRenderer ${OpenCV_LIBS})