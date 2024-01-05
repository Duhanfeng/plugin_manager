//
// Created by cxc on 2024/1/5.
//

#include <plugin_manager/plugin_encryption.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <fstream>

namespace ss
{
namespace plugin
{
    bool encryption(const std::string& src, const std::string& dst, unsigned char key)
    {
        namespace fs = boost::filesystem;
        if (!fs::exists(src))
        {
            return false;
        }

        //以二进制加载文件
        std::ifstream infile(src, std::ios::binary);
        std::ofstream outfile(dst, std::ios::binary);
        if (infile.fail() || outfile.fail())
        {
            infile.close();
            outfile.close();
            return false;
        }

        const size_t buffer_size = 4 * 1024; //选择一个合适的缓冲区大小
        char buffer[buffer_size];
        while (infile.read(buffer, buffer_size))
        {
            size_t bytes_read = infile.gcount();
            for (size_t i = 0; i < bytes_read; ++i)
            {
                buffer[i] ^= key;
            }
            outfile.write(buffer, bytes_read);
        }

        //处理最后一块可能不满缓冲区大小的数据
        size_t bytes_read = infile.gcount();
        for (size_t i = 0; i < bytes_read; ++i)
        {
            buffer[i] ^= key;
        }
        outfile.write(buffer, bytes_read);

        infile.close();
        outfile.close();

        return true;
    }
    bool decryption(const std::string& src, const std::string& dst, unsigned char key)
    {
        return encryption(src, dst, key);
    }

} //namespace plugin
} //namespace ss