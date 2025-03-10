# TempRenderer

Start from Scratch and Update Whenever

## 进展与规划
1. 变换 OK
2. 光栅化：
   - 深度缓冲 OK
   - 纹理贴图
     - 重心坐标uv OK
     - 贴图过小 插值
     - 贴图过大 mipmap
   - 抗锯齿
     - MSAA
     - FXAA
3. 简单键盘交互，窗口刷新 OK


## Current 3rd Party
1. OpenCV: show images and read textures
   - macos: brew install opencv, check OpenCV path in CmakeList
   - windows: fail to get it work over one day, wasted
2. rapidjson: read json files as configs
   - placed in thirdparty directory, check CmakeList
   - not included in git