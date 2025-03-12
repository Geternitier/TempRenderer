cmake_minimum_required(VERSION 3.21)
project(TempRenderer)

set(CMAKE_CXX_STANDARD 17)

include_directories(runtime)
include_directories(thirdparty)

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
        runtime/resource/cube.h
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
        scene/index.h
        runtime/resource/config.cpp
        runtime/resource/config.h
        runtime/render/mesh.cpp
        runtime/render/texture.cpp
        runtime/render/texture.h
        runtime/core/vector2f.h
        runtime/util/application.cpp
        runtime/util/application.h
        runtime/resource/sphere.h
        runtime/render/light/ambient.h
        runtime/render/material.h
        runtime/render/light/direction.h
        runtime/render/light/light.h
        runtime/render/light/light.cpp)

target_link_libraries(TempRenderer ${OpenCV_LIBS})