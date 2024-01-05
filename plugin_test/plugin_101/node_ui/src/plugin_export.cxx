#include "plugin_export.hpp"
#include <iostream>

const char* GetPluginGUID()
{
    return u8"3B42D785-B06A-1540-83C8-D3E29BAB31D3";
}

int GetUIPlatform()
{
    return 0;
}

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
void* CreatePluginUI(void* node, void* review, void* option)
{
    //std::cout << "CreatePluginUI" << std::endl;
    return nullptr;
}
void DisposePluginUI(void* plugin_ui)
{
    //std::cout << "DisposePluginUI" << std::endl;
}
