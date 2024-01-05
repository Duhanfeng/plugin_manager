//
// Created by cxc on 2024/1/4.
//

#pragma once

//-----导出接口定义

enum PluginType
{
    PluginType_Vision,        //视觉算法插件
    PluginType_Hardware,      //硬件插件
    PluginType_IO,            //IO插件
    PluginType_Communication, //通信插件
};

/*
    ----原始接口----
    GetPluginGUID: 获取插件GUID  http://www.ku51.net/guid/index.html  guid可在此网址中生成,插件之间的guid不得重复
    GetPluginCategory: 获取插件分类(旧版本兼容)
    GetPluginName: 获取插件名
    GetPluginDescription: 获取插件描述
    CreatePlugin: 插件构建
    ----扩展接口----
    GetPluginVersion: 获取插件版本
    GetPluginAuthor: 获取插件作者
    GetPluginCategoryAdv: 获取插件分类(新接口,支持多层结构,以'.'作为分割,如"3D.点云处理")
    GetPluginType: 获取插件类型
    InitPluginPlatform: 初始化插件平台,如果插件需要在create之前进行一些全局性的初始化,可以在此实现
    UninitPluginPlatform: 在程序退出之前进行全局性资源的释放操作
    DisposePlugin: 插件释放
*/

#define SS_PLUGIN_DEFINE SS_PLUGIN_DEFINE_IMPL
#define SS_PLUGIN_DEFINE_IMPL                                                                               \
    extern "C"                                                                                              \
    {                                                                                                       \
        SS_PLUGIN_EXPORT_API const char* GetPluginGUID();                                                   \
        SS_PLUGIN_EXPORT_API int GetPluginCategory();                                                       \
        SS_PLUGIN_EXPORT_API const char* GetPluginName();                                                   \
        SS_PLUGIN_EXPORT_API const char* GetPluginDescription();                                            \
        SS_PLUGIN_EXPORT_API void* CreatePlugin(void* option);                                              \
        SS_PLUGIN_EXPORT_API const char* GetPluginVersion();                                                \
        SS_PLUGIN_EXPORT_API const char* GetPluginAuthor();                                                 \
        SS_PLUGIN_EXPORT_API const char* GetPluginCategoryAdv();                                            \
        SS_PLUGIN_EXPORT_API int GetPluginType();                                                           \
        SS_PLUGIN_EXPORT_API void InitPluginPlatform(const char* resource_dir, int language, int platform); \
        SS_PLUGIN_EXPORT_API void UninitPluginPlatform();                                                   \
        SS_PLUGIN_EXPORT_API void DisposePlugin(void* plugin);                                              \
    }

//该宏写在C文件中
#define SS_PLUGIN_SETUP(guid, category, name, version, author, type, description) SS_PLUGIN_SETUP_IMPL(guid, category, name, version, author, type, description)
#define SS_PLUGIN_SETUP_IMPL(guid, category, name, version, author, type, description) \
    const char* GetPluginGUID() { return guid; }                                       \
    const char* GetPluginCategoryAdv() { return category; }                            \
    const char* GetPluginName() { return name; }                                       \
    const char* GetPluginVersion() { return version; }                                 \
    const char* GetPluginAuthor() { return author; }                                   \
    const char* GetPluginDescription() { return description; }                         \
    int GetPluginType() { return type; }                                               \
    int GetPluginCategory() { return 0; }

//-----导出接口定义(UI)

/*
    ----原始接口----
    GetPluginGUID: 获取插件GUID,该ID应当和上方对应Plugin导出的GUID严格保持一致
    CreatePlugin: 插件构建
    ----扩展接口----
    GetUIPlatform: 获取UI平台(预留),返回0即可
    InitPluginPlatform: 初始化插件平台,如果插件需要在create之前进行一些全局性的初始化,可以在此实现
    UninitPluginPlatform: 在程序退出之前进行全局性资源的释放操作
    DisposePlugin: 插件释放
*/

#define SS_UI_PLUGIN_DEFINE SS_UI_PLUGIN_DEFINE_IMPL
#define SS_UI_PLUGIN_DEFINE_IMPL                                                                               \
    extern "C"                                                                                                 \
    {                                                                                                          \
        SS_UI_PLUGIN_EXPORT_API const char* GetPluginGUID();                                                   \
        SS_UI_PLUGIN_EXPORT_API void* CreatePluginUI(void* node, void* review, void* option);                  \
        SS_UI_PLUGIN_EXPORT_API int GetUIPlatform();                                                           \
        SS_UI_PLUGIN_EXPORT_API void InitPluginPlatform(const char* resource_dir, int language, int platform); \
        SS_UI_PLUGIN_EXPORT_API void UninitPluginPlatform();                                                   \
        SS_UI_PLUGIN_EXPORT_API void DisposePluginUI(void* plugin_ui);                                         \
    }

namespace ss
{
struct PluginFunctions
{
    //----原始接口----
    using GetPluginGUID = const char* (*)();
    using GetPluginCategory = int (*)();
    using GetPluginName = const char* (*)();
    using GetPluginDescription = const char* (*)();
    using CreatePlugin = void* (*)(void* option);
    //----扩展接口----
    using GetPluginVersion = const char* (*)();
    using GetPluginAuthor = const char* (*)();
    using GetPluginCategoryAdv = const char* (*)();
    using GetPluginType = int (*)();
    using InitPluginPlatform = void (*)(const char*, int, int);
    using UninitPluginPlatform = void (*)();
    using DisposePlugin = void (*)(void*);

    //----原始接口----
    GetPluginGUID getPluginGUID = nullptr;
    GetPluginCategory getPluginCategory = nullptr;
    GetPluginName getPluginName = nullptr;
    GetPluginDescription getPluginDescription = nullptr;
    CreatePlugin createPlugin = nullptr;
    //----扩展接口----
    GetPluginVersion getPluginVersion = nullptr;
    GetPluginAuthor getPluginAuthor = nullptr;
    GetPluginCategoryAdv getPluginCategoryAdv = nullptr;
    GetPluginType getPluginType = nullptr;
    InitPluginPlatform initPluginPlatform = nullptr;
    UninitPluginPlatform uninitPluginPlatform = nullptr;
    DisposePlugin disposePlugin = nullptr;
};

struct UIPluginFunctions
{
    //----原始接口----
    using GetPluginGUID = const char* (*)();
    using CreatePluginUI = void* (*)(void*, void*, void*);
    //----扩展接口----
    using GetUIPlatform = int (*)();
    using InitPluginPlatform = void (*)(const char*, int, int);
    using UninitPluginPlatform = void (*)();
    using DisposePluginUI = void (*)(void* plugin);

    //----原始接口----
    GetPluginGUID getPluginGUID = nullptr;
    CreatePluginUI createPluginUI = nullptr;
    //----扩展接口----
    GetUIPlatform getUIPlatform = nullptr;
    InitPluginPlatform initPluginPlatform = nullptr;
    UninitPluginPlatform uninitPluginPlatform = nullptr;
    DisposePluginUI disposePluginUI = nullptr;
};

} //namespace ss
