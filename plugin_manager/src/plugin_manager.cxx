//
// Created by Duhanfeng on 2024/1/7.
//

#include <plugin_manager/plugin_manager.hpp>
#include <plugin_manager/plugin_pack.hpp>
#include <boost/filesystem.hpp>
#include "locale.hpp"

namespace ss
{
void PluginManager::init(const std::string& plugin_dir, const std::string& key)
{
    namespace fs = boost::filesystem;

    key_ = key;

    //字符编码转换
    std::string local_plugin_dir = toLocalString(plugin_dir);

    //查找目录下的所有文件
    fs::path src_dir(local_plugin_dir);
    if (!fs::exists(src_dir) || !fs::is_directory(src_dir))
    {
        return;
    }

    //输出路径
    std::string local_dst_dir = boost::filesystem::temp_directory_path().string() + "/.snapshot_temp/.plugin_unpack";
    std::string utf_dst_dir = toUtf8String(local_dst_dir);

    //遍历目录下的所有文件
    fs::recursive_directory_iterator itr(src_dir);
    fs::recursive_directory_iterator end_itr;
    while (itr != end_itr)
    {
        if (fs::is_regular_file(*itr) && itr->path().extension() == plugin_extension)
        {
            //获取插件的utf路径
            std::string utf_plugin_path = toUtf8String(itr->path().string());
            std::string utf_plugin_name = toUtf8String(itr->path().stem().string());

            std::string unpack_dir = utf_dst_dir + u8"/" + utf_plugin_name;

            //如果目标路径已经存在,则删除它
            std::string local_unpack_dir = toLocalString(unpack_dir);
            if (fs::exists(local_unpack_dir))
            {
                fs::remove_all(local_unpack_dir);
            }

            //解包到目标目录
            if (plugin::unpack(utf_plugin_path, unpack_dir))
            {
                //加载目标
                loadPlugin(unpack_dir);
            }
            else
            {
                //异常处理
            }
        }
        itr++;
    }
}
void PluginManager::loadPlugin(const std::string& dir)
{
    //是否需要进行dll的数据加密/解密?

    std::string vision_dll_path = dir + ""; //视觉dll路径
    std::string widget_dll_path;            //窗体dll路径
    std::string icon_path;                  //icon文件路径
    std::string custom_resource_dir;        //自定义资源路径
    std::string custom_dependent_dir;       //自定义依赖动态库路径
}

std::unordered_map<std::string, PluginResources>& PluginManager::resources()
{
    return resources_;
}
const std::unordered_map<std::string, PluginResources>& PluginManager::resources() const
{
    return resources_;
}

} //namespace ss
