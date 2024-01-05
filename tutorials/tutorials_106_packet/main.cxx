#include <iostream>
#include <boost/dll.hpp>
#include <unordered_map>
#include <plugin_manager/plugin.hpp>
#include <plugin_manager/plugin_loader.hpp>
#include <plugin_manager/plugin_encryption.hpp>
#include <boost/filesystem.hpp>
#include "timer.hpp"
#include <fstream>

#include <minizip/zip.h>
#include <minizip/unzip.h>
#include <minizip/mz.h>
#include <minizip/mz_strm.h>
#include <minizip/mz_zip.h>
#include <minizip/mz_zip_rw.h>
#include <minizip/mz_os.h>
#include <minizip/mz_compat.h>
#include <minizip/mz_crypt.h>

bool packet(const std::string& src_dir, const std::string& dst_file)
{
    void* zip_handle = mz_zip_writer_create();
    mz_zip_writer_set_compress_level(zip_handle, 0);             //不压缩
    mz_zip_writer_open_file(zip_handle, dst_file.c_str(), 0, 0); //打开zip文件进行写入
    int err = mz_zip_writer_add_path(zip_handle, src_dir.c_str(), nullptr, 0, 1);
    mz_zip_writer_close(zip_handle);   //关闭zip文件写入
    mz_zip_writer_delete(&zip_handle); //释放zip写入句柄
    return err == MZ_OK;
}

bool unpack(const std::string& src_file, const std::string& dst_dir)
{
    //打开文件
    void* zip_reader = mz_zip_reader_create();
    int err = mz_zip_reader_open_file(zip_reader, src_file.c_str());
    if (err != MZ_OK)
    {
        mz_zip_reader_delete(&zip_reader);
        return false;
    }

    //解压到目录
    err = mz_zip_reader_save_all(zip_reader, dst_dir.c_str());
    mz_zip_reader_close(zip_reader);
    mz_zip_reader_delete(&zip_reader);

    return err == MZ_OK;
}

int main()
{
    std::string data_dir = std::string(DATA_DIR);
    //std::string src_dir = data_dir + "/plugin";

    std::string src_dir = u8"新建文件夹";
    std::string dst_file = "./packet.flow";

    Timer timer;
    if (packet(src_dir, dst_file))
    {
        std::cout << "packet success!" << std::endl;
    }
    else
    {
        std::cout << "packet error!" << std::endl;
    }
    timer.out("packet");

    std::string unpack_src_file = dst_file;
    std::string unpack_dst_dir = "./unpack";

    timer.reset();
    unpack(unpack_src_file, unpack_dst_dir);
    timer.out("unpack");

    std::cout << "\n\n\nfinish" << std::endl;
    return 0;
}
