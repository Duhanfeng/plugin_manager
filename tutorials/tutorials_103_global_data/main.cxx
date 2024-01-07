#include <iostream>
#include <boost/dll.hpp>
#include <unordered_map>
#include <plugin_manager/plugin.hpp>
#include <plugin_manager/plugin_loader.hpp>

/*
 * 测试项: 加载插件,然后打印插件信息,然后释放资源
 * */

bool is_test_loop = true; //true: 循环测试,不打印消息,用于跟踪内存释放情况;  false: 单次测试,打印插件消息,用于测试插件加载是否成功

std::unordered_map<std::string, std::shared_ptr<boost::dll::shared_library>> plugin_libs;
std::unordered_map<std::string, ss::PluginFunctions> plugin_functions;

std::unordered_map<std::string, std::shared_ptr<boost::dll::shared_library>> ui_plugin_libs;
std::unordered_map<std::string, ss::UIPluginFunctions> ui_plugin_functions;

void load_plugin_test()
{
    if (!is_test_loop)
    {
        std::cout << "load_plugin_test" << std::endl;
    }

    std::string data_dir = std::string(DATA_DIR);
    std::string file = data_dir + u8"/插件/100/Plugin.103.dll";

    ss::PluginFunctions functions;
    auto lib = ss::plugin::loadPlugin(file, functions);
    if (lib == nullptr)
    {
        return;
    }
    std::string type_id = functions.getPluginGUID();
    if (type_id.empty())
    {
        return;
    }

    //添加资源
    plugin_libs[type_id] = lib;
    plugin_functions[type_id] = functions;

    //测试
    plugin_functions[type_id].initPluginPlatform("", 0, 0);
    for (int i = 0; i < 100; ++i)
    {
        auto plugin = plugin_functions[type_id].createPlugin(nullptr);
        plugin_functions[type_id].disposePlugin(plugin);
    }
    plugin_functions[type_id].uninitPluginPlatform();
}

void dispose()
{
    ui_plugin_functions.clear();
    for (const auto& lib : ui_plugin_libs)
    {
        lib.second->unload();
    }
    ui_plugin_libs.clear();
    plugin_functions.clear();
    for (const auto& lib : plugin_libs)
    {
        lib.second->unload();
    }
    plugin_libs.clear();
}

int main()
{
    do
    {
        load_plugin_test();
        dispose();
    } while (is_test_loop);

    std::cout << "\n\n\nfinish" << std::endl;

    return 0;
}
