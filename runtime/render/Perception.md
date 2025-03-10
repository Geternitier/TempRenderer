# Perception in Rendering

## 渲染前
1. 窗口：分辨率（宽$\times$高）
   - Screen类，使用静态成员和静态函数提供
2. 相机：观察点坐标系，fov，视锥远近截面z轴位置
   - Camera类：位置, 上方, 视线方向，fov，near和far
     - 提供curCamera静态成员查找当前相机
     - 观察点坐标系给出View变换矩阵
     - fov、near和far给出透视投影变换矩阵
     - 另外提供正交投影变换矩阵静态函数
3. 顶点集合：顶点（位置、颜色）
   - Mesh类：顶点数、顶点数组、三角形（顶点索引）数、三角形数组
     - 提供保存到.mesh文件和读取.mesh文件功能

## 渲染中
1. 场景坐标系、三角形：Mesh中给出
2. View变换：Camera给出
3. Projection变换：Camera给出
4. Viewport变换：直接计算
5. 光栅化：先计算包围盒，然后用重心坐标进行插值计算，使用深度缓冲

## 渲染后
1. 使用OpenCV绘图显示。