# SFML 小项目

## 简介
一个使用 **C++ 和 SFML** 编写的简单项目。
目前已完成游戏页面的基本框架，支持多级页面切换。
后续将继续完善框架，然后着手游戏页面逻辑。

项目主要用于学习C++和面向对象。

---

## 开发环境

- 操作系统：Windows 10 / 11
- 编译器：MinGW-w64（支持 C++20）
- IDE：Visual Studio Code
- C++ 标准：C++20

---

## 依赖库

- **SFML 3.0.2**
  - sfml-graphics
  - sfml-window
  - sfml-system

确保安装SFML，并配置好环境变量或在编译时指定include/lib路径。

---

## 编译方式

使用 g++ 手动编译（示例）：

```bash
g++ main.cpp application.cpp MenuState.cpp DifficultyState.cpp \
    ManualState.cpp Button.cpp StateStack.cpp \
    -std=c++20 \
    -IC:/msys64/mingw64/include \
    -LC:/msys64/mingw64/lib \
    -lsfml-graphics -lsfml-window -lsfml-system \
    -o main.exe

--- 

## 运行方式

编译成功后，运行生成在根目录的可执行文件
./main.exe

---

## 操作说明

主菜单
- Up / Down： 选择按钮
- Z： 确定
- X / Esc： 选择Quit

Start页
- Up / Down / Left / Right： 选择按钮
- Z： 确定
- X / Esc： 返回上一级菜单

Manual页
- Left / Right： 翻页
- X / Esc： 返回上一级菜单

---

## 项目结构

.
├─ main.cpp              // 程序入口
├─ application.cpp       // 应用主逻辑
├─ StateStack.cpp        // 状态栈管理
├─ MenuState.cpp         // 菜单界面
├─ DifficultyState.cpp   // 难度选择界面
├─ ManualState.cpp       // 游戏说明界面
├─ Button.cpp            // 按钮组件
├─ Text.cpp              // 显示文本组件
├─ .vscode/              // VS Code 配置文件
└─ README.md
