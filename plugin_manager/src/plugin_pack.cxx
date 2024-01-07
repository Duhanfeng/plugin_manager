//
// Created by Duhanfeng on 2024/1/7.
//

#include <plugin_manager/plugin_pack.hpp>

#include <fstream>
#include <boost/filesystem.hpp>
#include <minizip/zip.h>
#include <minizip/unzip.h>
#include <minizip/mz.h>
#include <minizip/mz_strm.h>
#include <minizip/mz_zip.h>
#include <minizip/mz_zip_rw.h>
#include <minizip/mz_os.h>
#include "locale.hpp"

namespace ss
{
namespace plugin
{
    //打包
    bool pack(const std::string& src_dir, const std::string& dst_file)
    {
        //字符编码转换
        //std::string local_src_dir = toLocalString(src_dir);
        //std::string local_dst_file = toLocalString(dst_file);

        void* zip_handle = mz_zip_writer_create();
        mz_zip_writer_set_compress_level(zip_handle, 0);             //不压缩
        mz_zip_writer_open_file(zip_handle, dst_file.c_str(), 0, 0); //打开zip文件进行写入
        int err = mz_zip_writer_add_path(zip_handle, src_dir.c_str(), nullptr, 0, 1);
        mz_zip_writer_close(zip_handle);   //关闭zip文件写入
        mz_zip_writer_delete(&zip_handle); //释放zip写入句柄
        return err == MZ_OK;
    }
    bool pack(const std::string& src_dir, const std::string& dst_file, const std::string& password)
    {
        //字符编码转换
        //std::string local_src_dir = toLocalString(src_dir);
        //std::string local_dst_file = toLocalString(dst_file);

        void* zip_handle = mz_zip_writer_create();
        mz_zip_writer_set_compress_level(zip_handle, 0);             //不压缩
        mz_zip_writer_set_password(zip_handle, password.c_str());    //设置密码
        mz_zip_writer_open_file(zip_handle, dst_file.c_str(), 0, 0); //打开zip文件进行写入
        int err = mz_zip_writer_add_path(zip_handle, src_dir.c_str(), nullptr, 0, 1);
        mz_zip_writer_close(zip_handle);   //关闭zip文件写入
        mz_zip_writer_delete(&zip_handle); //释放zip写入句柄
        return err == MZ_OK;
    }
    //拆包
    bool unpack(const std::string& src_file, const std::string& dst_dir)
    {
        //字符编码转换
        //std::string local_src_file = toLocalString(src_file);
        //std::string local_dst_dir = toLocalString(dst_dir);

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
    bool unpack(const std::string& src_file, const std::string& dst_dir, const std::string& password)
    {
        //字符编码转换
        //std::string local_src_file = toLocalString(src_file);
        //std::string local_dst_dir = toLocalString(dst_dir);

        //打开文件
        void* zip_reader = mz_zip_reader_create();
        mz_zip_reader_set_password(zip_reader, password.c_str());
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

} //namespace plugin

} //namespace ss