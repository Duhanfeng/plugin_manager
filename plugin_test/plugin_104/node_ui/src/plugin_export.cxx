#include "plugin_export.hpp"
#include <iostream>
#include "node.hpp"

const char* GetPluginGUID()
{
    return u8"4FD449BE-9D53-DE17-C3DD-6F4427EB6355";
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
    return new NodeUI((Node*)node);
}
void DisposePluginUI(void* plugin_ui)
{
    if (plugin_ui != nullptr)
    {
        delete (NodeUI*)plugin_ui;
    }
    //std::cout << "DisposePluginUI" << std::endl;
}
