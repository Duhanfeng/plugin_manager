#include "plugin_export.hpp"
#include <iostream>
#include <node.hpp>
#include "global_data.hpp"
#include <GLFW/glfw3.h>

//初始化/释放
void InitPluginPlatform(const char* resource_dir, int language, int platform)
{
    //初始化opengl版本
    if (!glfwInit())
    {
        return;
    }

    int major, minor, rev;
    glfwGetVersion(&major, &minor, &rev);

    //声明opengl版本(GL 3.0 + GLSL 130)  GLSL: opengl的着色器语言
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    std::cout << u8"opengl version: " << major << "." << minor << "." << rev << std::endl;

    //通过几何上下文创建窗体
    GLFWwindow* window = glfwCreateWindow(1280, 720, u8"你好 Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
    if (window == nullptr)
    {
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); //Enable vsync

    while (!glfwWindowShouldClose(window)) //当不关闭窗口是
    {
        glfwPollEvents(); //检查有没有触发什么事件（比如键盘输入、鼠标移动等）

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //渲染指令
        glClearColor(0.71f, 0.21f, 0.1f, 0.1f); //清空屏幕颜色。在调用参数里设置的颜色
        glClear(GL_COLOR_BUFFER_BIT);           //清空屏幕的缓冲，可能清空的有颜色/深度/模板缓冲

        //检查并调用事件，交换缓冲
        glfwSwapBuffers(window); //交换前后缓冲器
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    //std::cout << "InitPluginPlatform" << std::endl;
    global::data = new int[10000u * 10000u * 50u];
}
void UninitPluginPlatform()
{
    //std::cout << "UninitPluginPlatform" << std::endl;
    delete[] global::data;
    global::data = nullptr;
}

//资源构造/释放
void* CreatePlugin(void* option)
{
    return new Node();
}
void DisposePlugin(void* plugin)
{
    if (plugin != nullptr)
    {
        delete (Node*)plugin;
    }
}

//注册插件
SS_PLUGIN_SETUP(u8"4FD449BE-9D53-DE17-C3DD-6F4427EB6355", u8"3D.3D_PointCloud_Process", u8"plugin_104",
    u8"V1.0", u8"QingCheng", PluginType_Vision, u8"plugin_104: Convert Depth Image To PointCloud(Debug)")
