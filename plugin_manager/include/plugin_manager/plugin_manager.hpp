//
// Created by Duhanfeng on 2024/1/7.
//

#pragma once
#include <string>
#include <boost/dll.hpp>
#include "plugin.hpp"
#include "export_def.hpp"

namespace ss
{
class PluginInfos
{
public:
    //原始接口信息
    std::string type_id;     //类型ID
    int category = 0;        //类型[废弃]
    std::string name;        //名字
    std::string description; //描述
    //扩展接口信息
    std::string version;                      //版本号
    std::string author;                       //作者
    std::string category_adv;                 //插件分类
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

class PluginManager
{
public:



};

} //namespace ss
