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
    std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, ss::PluginFunctions& functions);
    std::shared_ptr<boost::dll::shared_library> loadPlugin(const std::string& file, ss::UIPluginFunctions& functions);
}
} //namespace ss
