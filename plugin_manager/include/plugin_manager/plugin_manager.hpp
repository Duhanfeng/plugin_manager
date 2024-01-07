//
// Created by Duhanfeng on 2024/1/7.
//

#pragma once
#include <string>
#include <unordered_map>
#include <boost/dll.hpp>
#include "plugin.hpp"
#include "export_def.hpp"

namespace ss
{
class PluginInfos
{
public:
    //原始接口信息
    std::string type_id;     //ID
    int category = 0;        //类别[废弃]
    std::string name;        //名字
    std::string description; //描述
    //扩展接口信息
    std::string version;                      //版本号
    std::string author;                       //作者
    std::string category_adv;                 //类别
    int type = PluginType::PluginType_Vision; //插件类型
};

class PluginContentPaths
{
public:
    //路径(utf-8格式)
    std::string vision_dll_path;      //视觉dll路径
    std::string widget_dll_path;      //窗体dll路径
    std::string icon_path;            //icon文件路径
    std::string custom_resource_dir;  //自定义资源路径
    std::string custom_dependent_dir; //自定义依赖动态库路径
};

class PluginResources
{
public:
    PluginInfos infos;                                         //插件信息
    PluginContentPaths content_path;                           //插件内容路径
    PluginFunctions functions;                                 //插件函数接口
    UIPluginFunctions ui_functions;                            //UI插件函数接口
    std::shared_ptr<boost::dll::shared_library> plugin_lib;    //插件动态库对象
    std::shared_ptr<boost::dll::shared_library> ui_plugin_lib; //UI插件动态库对象
};

class SS_PM_EXPORT_API PluginManager
{
public:
    void init(const std::string& plugin_dir, const std::string& key);

    std::unordered_map<std::string, PluginResources>& resources();
    const std::unordered_map<std::string, PluginResources>& resources() const;

protected:
    void loadPlugin(const std::string& dir);

protected:
    const std::string plugin_extension = ".xplugin";
    std::unordered_map<std::string, PluginResources> resources_;
    std::string key_;
};

SS_PM_EXPORT_API bool packPlugin(const std::string& src_plugin_dir, const std::string& dst_plugin_file, const std::string& key);

} //namespace ss
