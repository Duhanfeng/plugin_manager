//
// Created by cxc on 2024/1/5.
//

#pragma once
#include <string>

namespace ss
{
namespace plugin
{
    //加密
    bool encryption(const std::string& src, const std::string& dst, unsigned char key);
    //解密
    bool decryption(const std::string& src, const std::string& dst, unsigned char key);
}
} //namespace ss
