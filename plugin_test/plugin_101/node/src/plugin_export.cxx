#include "plugin_export.hpp"
#include <iostream>

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
    //std::cout << "CreatePlugin" << std::endl;
    return nullptr;
}
void DisposePlugin(void* plugin)
{
    //std::cout << "DisposePlugin" << std::endl;
}

//注册插件
SS_PLUGIN_SETUP(u8"3B42D785-B06A-1540-83C8-D3E29BAB31D3", u8"3D.3D_PointCloud_Process", u8"plugin_101",
    u8"V1.0", u8"QingCheng", PluginType_Vision, u8"plugin_101: Convert Depth Image To PointCloud(Debug)")
