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
    std::string file = data_dir + "/plugin/100/Plugin.101.dll";

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

    //打印信息
    if (is_test_loop)
    {
        plugin_functions[type_id].getPluginGUID();
        plugin_functions[type_id].getPluginCategory();
        plugin_functions[type_id].getPluginName();
        plugin_functions[type_id].getPluginDescription();
        plugin_functions[type_id].getPluginVersion();
        plugin_functions[type_id].getPluginAuthor();
        plugin_functions[type_id].getPluginCategoryAdv();
        plugin_functions[type_id].getPluginType();
    }
    else
    {
        std::cout << "GetPluginGUID: " << plugin_functions[type_id].getPluginGUID() << std::endl;
        std::cout << "getPluginCategory: " << plugin_functions[type_id].getPluginCategory() << std::endl;
        std::cout << "getPluginName: " << plugin_functions[type_id].getPluginName() << std::endl;
        std::cout << "getPluginDescription: " << plugin_functions[type_id].getPluginDescription() << std::endl;
        std::cout << "getPluginVersion: " << plugin_functions[type_id].getPluginVersion() << std::endl;
        std::cout << "getPluginAuthor: " << plugin_functions[type_id].getPluginAuthor() << std::endl;
        std::cout << "getPluginCategoryAdv: " << plugin_functions[type_id].getPluginCategoryAdv() << std::endl;
        std::cout << "getPluginType: " << plugin_functions[type_id].getPluginType() << std::endl;
    }

    auto plugin = plugin_functions[type_id].createPlugin(nullptr);
    plugin_functions[type_id].disposePlugin(plugin);
    plugin_functions[type_id].uninitPluginPlatform();
}

void load_ui_plugin_test()
{
    if (!is_test_loop)
    {
        std::cout << "load_ui_plugin_test" << std::endl;
    }

    std::string data_dir = std::string(DATA_DIR);
    std::string file = data_dir + "/plugin/100/Plugin.101.Control.dll";

    ss::UIPluginFunctions functions;
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
    ui_plugin_libs[type_id] = lib;
    ui_plugin_functions[type_id] = functions;

    //测试
    ui_plugin_functions[type_id].initPluginPlatform("", 0, 0);

    if (is_test_loop)
    {
        ui_plugin_functions[type_id].getPluginGUID();
        ui_plugin_functions[type_id].getUIPlatform();
    }
    else
    {
        //打印信息
        std::cout << "GetPluginGUID: " << ui_plugin_functions[type_id].getPluginGUID() << std::endl;
        std::cout << "getUIPlatform: " << ui_plugin_functions[type_id].getUIPlatform() << std::endl;
    }

    auto plugin = ui_plugin_functions[type_id].createPluginUI(nullptr, nullptr, nullptr);
    ui_plugin_functions[type_id].disposePluginUI(plugin);
    ui_plugin_functions[type_id].uninitPluginPlatform();
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
    int loop_count = is_test_loop ? 100000 : 1;

    do
    {
        load_plugin_test();
        load_ui_plugin_test();
        dispose();
    } while (is_test_loop);

    std::cout << "\n\n\nfinish" << std::endl;

    return 0;
}
