# TempRenderer

Start from Scratch and Update Whenever

## 进展与规划
1. 变换 OK
2. 光栅化：Forward Rendering
   - 深度缓冲 OK
   - 纹理贴图
     - 重心坐标插值 OK
     - 贴图过小 插值
     - 贴图过大 mipmap
   - 抗锯齿
     - MSAA
     - FXAA
   - 基于PBR材质的光照 OK
   - Shadow Mapping
   - 透明物体的渲染
3. 简单键盘交互，窗口刷新 OK
4. 可渲染对象：
   - 几何体
     - 显式Mesh OK
     - 隐式
   - 地理
   - 大气
5. 项目结构
   - Components: 需要反射
   - 使用json构建设置与资源
6. 性能优化
   - GPU
   - 多线程

## Project Structure
1. runtime 
   - runtime/util/application.cpp: executing logic
   - runtime/core: data structures and algorithms
   - runtime/render: render components
   - runtime/resource: filepath config and basic geometry mesh builder
2. asset: containing things like images

## 3rd Party
1. OpenCV: show and read images
   - macOS: brew install opencv, check OpenCV path in CmakeList
   - windows: fail to get it work over one day, wasted
   - ridiculous input system, may abandon