#include <iostream>
#include <boost/dll.hpp>
#include <boost/filesystem.hpp>
#include <unordered_map>
#include <plugin_manager/plugin.hpp>
#include <plugin_manager/plugin_loader.hpp>
#include <plugin_manager/plugin_encryption.hpp>
#include <plugin_manager/plugin_pack.hpp>
#include <plugin_manager/plugin_manager.hpp>
#include <boost/filesystem.hpp>
#include "timer.hpp"

int main()
{
    std::string data_dir = std::string(DATA_DIR);
    std::string src_dir = data_dir + u8"/插件";

    boost::filesystem::path temp_dir = boost::filesystem::temp_directory_path();
    boost::filesystem::path temp_file_path = temp_dir / "my_temp_file.txt";

    ss::PluginManager plugin_manager;
    plugin_manager.init("plugin", "");

    std::cout << "temp_dir: " << temp_dir << std::endl;

    std::cout << "\n\n\nfinish" << std::endl;
    return 0;
}
