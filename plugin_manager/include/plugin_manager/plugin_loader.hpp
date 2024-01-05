//
// Created by cxc on 2024/1/4.
//

#pragma once
#include <string>
#include <memory>
#include <boost/dll.hpp>
#include <plugin_manager/plugin.hpp>

namespace ss
{
namespace plugin
{
    //追加DLL搜寻路径
    bool appendDllSearchPath(const std::string& path);
    bool appendDllSearchPaths(const std::vector<std::string>& paths);

    std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, ss::PluginFunctions& functions);
    std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, ss::UIPluginFunctions& functions);

    std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, const std::string& dependent_dir, ss::PluginFunctions& functions);
    std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, const std::string& dependent_dir, ss::UIPluginFunctions& functions);

} //namespace plugin
} //namespace ss
