#include "plugin_export.hpp"
#include <iostream>
#include <node.hpp>
#include "global_data.hpp"

//初始化/释放
void InitPluginPlatform(const char* resource_dir, int language, int platform)
{
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
SS_PLUGIN_SETUP(u8"4FD449BE-9D53-DE17-C3DD-6F4427EB6355", u8"3D.3D_PointCloud_Process", u8"plugin_103",
    u8"V1.0", u8"QingCheng", PluginType_Vision, u8"plugin_101: Convert Depth Image To PointCloud(Debug)")
