#include <iostream>
#include <boost/dll.hpp>
#include <unordered_map>
#include <plugin_manager/plugin.hpp>
#include <plugin_manager/plugin_loader.hpp>
#include <plugin_manager/plugin_encryption.hpp>
#include <plugin_manager/plugin_pack.hpp>
#include <boost/filesystem.hpp>
#include "timer.hpp"

int main()
{
    std::string data_dir = std::string(DATA_DIR);
    std::string src_dir = data_dir + u8"/插件";

    //std::string src_dir = u8"新建文件夹";
    std::string dst_file = u8"./插件.zip";

    Timer timer;
    if (ss::plugin::pack(src_dir, dst_file, u8"12254"))
    {
        std::cout << "packet success!" << std::endl;
    }
    else
    {
        std::cout << "packet error!" << std::endl;
    }
    timer.out("packet");

    std::string unpack_src_file = dst_file;
    std::string unpack_dst_dir = u8"./解包";

    timer.reset();
    if (ss::plugin::unpack(unpack_src_file, unpack_dst_dir, "12254"))
    {
        std::cout << "unpack success!" << std::endl;
    }
    else
    {
        std::cout << "unpack error!" << std::endl;
    }
    timer.out("unpack");

    std::cout << "\n\n\nfinish" << std::endl;
    return 0;
}
