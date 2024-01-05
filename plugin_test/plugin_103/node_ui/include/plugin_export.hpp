#pragma once

#include <plugin_manager/plugin.hpp>

//-----导出符号定义
#ifndef SS_UI_PLUGIN_EXPORT_API
#if (defined _WIN32 || defined WINCE || defined __CYGWIN__) && defined(SS_UI_PLUGIN_EXPORT_FLAG)
#define SS_UI_PLUGIN_EXPORT_API __declspec(dllexport)
#elif defined __GNUC__ && __GNUC__ >= 4 && (defined(SS_UI_PLUGIN_EXPORT_FLAG) || defined(__APPLE__))
#define SS_UI_PLUGIN_EXPORT_API __attribute__((visibility("default")))
#endif
#endif

#ifndef SS_UI_PLUGIN_EXPORT_API
#define SS_UI_PLUGIN_EXPORT_API
#endif

//-----接口导出
SS_UI_PLUGIN_DEFINE
