#include <iostream>
#include <boost/dll.hpp>
#include <unordered_map>
#include <plugin_manager/plugin.hpp>
#include <plugin_manager/plugin_loader.hpp>
#include <plugin_manager/plugin_encryption.hpp>
#include <boost/filesystem.hpp>
#include "timer.hpp"

void base_test()
{
    std::string data_dir = std::string(DATA_DIR);

    //对文件进行加密
    std::string encryption_file = data_dir + "/plugin/100/Plugin.105.x_plugin";
    std::string decryption_file = data_dir + "/plugin/100/Plugin.105.dll";

    //如果加密文件不存在,则先进行加密
    if (!boost::filesystem::exists(encryption_file))
    {
        std::string file = data_dir + "/plugin/100/Plugin.103.dll";
        ss::plugin::encryption(file, encryption_file, 0x3D);
    }

    //解密
    ss::plugin::decryption(encryption_file, decryption_file, 0x3D);

    ss::PluginFunctions functions;
    std::shared_ptr<boost::dll::shared_library> lib = ss::plugin::loadPlugin(decryption_file, functions);

    //打印消息
    std::cout << "GetPluginGUID: " << functions.getPluginGUID() << std::endl;
    std::cout << "getPluginCategory: " << functions.getPluginCategory() << std::endl;
    std::cout << "getPluginName: " << functions.getPluginName() << std::endl;
    std::cout << "getPluginDescription: " << functions.getPluginDescription() << std::endl;
    std::cout << "getPluginVersion: " << functions.getPluginVersion() << std::endl;
    std::cout << "getPluginAuthor: " << functions.getPluginAuthor() << std::endl;
    std::cout << "getPluginCategoryAdv: " << functions.getPluginCategoryAdv() << std::endl;
    std::cout << "getPluginType: " << functions.getPluginType() << std::endl;
}

void performanceTest()
{
    namespace fs = boost::filesystem;
    std::string data_dir = std::string(DATA_DIR);
    std::string encryption_file = data_dir + "/packet/105/105.ss_plugin";

    if (!fs::exists(encryption_file))
    {
        std::cerr << "file is not exist!" << std::endl;
        std::exit(-1);
    }

    //测试解密性能
    Timer timer;
    std::string decryption_dir = "./packet/105/decryption";
    if (!fs::exists(decryption_dir))
    {
        fs::create_directories(decryption_dir);
    }
    for (int i = 0; i < 1000; ++i)
    {
        std::string decryption_file = decryption_dir + "/" + std::to_string(i) + ".dll";
        ss::plugin::decryption(encryption_file, decryption_file, 0X2D);
    }
    timer.out(""); //20240105: 在笔记本 i7-12700H 中, 测试结果为: 4434.9ms
}

int main()
{
    base_test();
    performanceTest();

    std::cout << "\n\n\nfinish" << std::endl;
    return 0;
}
