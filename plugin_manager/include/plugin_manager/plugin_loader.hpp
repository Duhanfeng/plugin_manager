//
// Created by cxc on 2024/1/4.
//

#pragma once
#include <string>
#include <memory>
#include <boost/dll.hpp>
#include <plugin_manager/plugin.hpp>
#include "export_def.hpp"

namespace ss
{
namespace plugin
{
    //追加DLL搜寻路径
    SS_PM_EXPORT_API bool appendDllSearchPath(const std::string& path);
    SS_PM_EXPORT_API bool appendDllSearchPaths(const std::vector<std::string>& paths);

    //加载插件
    SS_PM_EXPORT_API std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, ss::PluginFunctions& functions);
    SS_PM_EXPORT_API std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, ss::UIPluginFunctions& functions);

    //加载插件(并将其依赖路径添加进dll搜索路径中)
    SS_PM_EXPORT_API std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, const std::string& dependent_dir, ss::PluginFunctions& functions);
    SS_PM_EXPORT_API std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, const std::string& dependent_dir, ss::UIPluginFunctions& functions);

} //namespace plugin
} //namespace ss
