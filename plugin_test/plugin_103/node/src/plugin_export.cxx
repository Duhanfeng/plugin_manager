#include "plugin_export.hpp"
#include <iostream>
#include <node.hpp>

//初始化/释放
void InitPluginPlatform(const char* resource_dir, int language, int platform)
{
    //std::cout << "InitPluginPlatform" << std::endl;
}
void UninitPluginPlatform()
{
    //std::cout << "UninitPluginPlatform" << std::endl;
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
SS_PLUGIN_SETUP(u8"4C3DC439-95C7-C0B8-77BA-54221B9C10B5", u8"3D.3D_PointCloud_Process", u8"plugin_102",
    u8"V1.0", u8"QingCheng", PluginType_Vision, u8"plugin_101: Convert Depth Image To PointCloud(Debug)")
