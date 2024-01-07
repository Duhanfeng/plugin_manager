//
// Created by Duhanfeng on 2024/1/7.
//

#pragma once
#include <string>
#include "export_def.hpp"

namespace ss
{
namespace plugin
{
    //打包
    SS_PM_EXPORT_API bool pack(const std::string& src_dir, const std::string& dst_file);
    //拆包
    SS_PM_EXPORT_API bool unpack(const std::string& src_file, const std::string& dst_dir);

} //namespace plugin
} //namespace ss
