# Yousya's Game

Yousya's Game（勇者的游戏）是一款 Windows 平台的 C++ 控制台剧情 RPG，由 paulzrm 于 2026 年 1 月至 2 月独立完成。

玩家将扮演一名被召唤到异世界的“勇者”，在字符地图中移动、收集资源、与敌人战斗并推进剧情。游戏设计包含教程、敌人视野与追踪、武器方向、传送、障碍、存档以及多结局系统。

## 操作

- `W / A / S / D`：移动
- 方向键：改变武器方向并攻击
- `C`：在身后放置障碍
- `F`：传送

游戏内包含完整教程，开始新游戏后可按引导熟悉操作。

## 特性

- 彩色字符地图与实时刷新
- 具有方向、视野和移动逻辑的敌人
- 金币、生命值、障碍与传送机制
- 新游戏、继续游戏与存档读取
- 剧情分支和多个可收集结局
- 模块化的地图、玩家、敌人、战斗和存档代码

## 构建环境

项目使用 C++ 编写，并使用 Windows API 读取键盘状态，因此目前面向 Windows。

源码统一采用 UTF-8 编码。程序启动时会把 Windows 控制台输入、输出代码页切换为 UTF-8，并启用 ANSI 颜色支持，因此不依赖操作系统的默认中文代码页。

使用 CMake 构建：

```powershell
cmake -S . -B build
cmake --build build --config Release
```

`CMakeLists.txt` 会为 MSVC 添加 `/utf-8`，为 MinGW/GCC 添加 UTF-8 输入与执行字符集参数。建议使用 Windows Terminal 或其他支持 UTF-8 和 ANSI 转义序列的终端运行。

仓库不包含本地生成的可执行文件、预编译头、存档和旧版开发副本。

## 剧透说明

仓库中的 `readme(剧透向).md` 包含故事设定和预定结局方向，建议通关或不介意剧透后阅读。

## Author

Ruimin Zhang / paulzrm

Developed independently from January to February 2026.
