//
// Created by cxc on 2024/1/5.
//

#pragma once
#include <string>
#include "export_def.hpp"

namespace ss
{
namespace plugin
{
    //加密
    SS_PM_EXPORT_API bool encryption(const std::string& src, const std::string& dst, unsigned char key);
    //解密
    SS_PM_EXPORT_API bool decryption(const std::string& src, const std::string& dst, unsigned char key);

} //namespace plugin
} //namespace ss
