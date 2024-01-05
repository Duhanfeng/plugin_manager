#include <iostream>
#include <plugin/plugin.hpp>
#include <boost/dll.hpp>
#include <unordered_map>
#include "plugin_loader.hpp"

int main()
{
    std::vector<boost::dll::shared_library> ui_libs;

    std::unordered_map<std::string, std::shared_ptr<boost::dll::shared_library>> plugin_libs;
    std::unordered_map<std::string, ss::PluginFunctions> plugin_functions;

    ss::PluginFunctions functions;
    auto lib = ss::plugin::loadPlugin("Plugin.Test1.dll", functions);
    if (lib == nullptr)
    {
        return 0;
    }
    std::string type_id = functions.getPluginGUID();
    if (type_id.empty())
    {
        return 0;
    }

    //添加资源
    auto itr = plugin_libs.find(type_id);
    if (itr != plugin_libs.end())
    {
        std::cout << u8"存在重复TypeID的插件" << std::endl;
        return 0;
    }
    plugin_libs.emplace(type_id, lib);
    plugin_functions.emplace(type_id, functions);

    //测试
    plugin_functions[type_id].initPluginPlatform("", 0, 0);
    auto plugin = plugin_functions[type_id].createPlugin(nullptr);
    plugin_functions[type_id].disposePlugin(plugin);
    plugin_functions[type_id].uninitPluginPlatform();

    std::cout << "finish" << std::endl;

    return 0;
}
