#pragma once
#include <string>

namespace ss
{
//框架内部的所有字符串都用utf-8描述,但是window不支持使用utf-8中文字符串进行本地文件操作,所以添加一层本地化的转换
//但是对于linux系统而言,尚未测试其对其utf-8中文路径的支持性,在非window系统中,直接使用其utf-8路径
 std::string toLocalString(const std::string& str);

 std::string toUtf8String(const std::string& str);

} //namespace ss
