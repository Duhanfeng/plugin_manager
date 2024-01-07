//
// Created by Duhanfeng on 2024/1/7.
//

#pragma once

//-----导出符号定义
#ifndef SS_PM_EXPORT_API
#if (defined _WIN32 || defined WINCE || defined __CYGWIN__) && defined(SS_PM_EXPORT_FLAG)
#define SS_PM_EXPORT_API __declspec(dllexport)
#elif defined __GNUC__ && __GNUC__ >= 4 && (defined(SS_PM_EXPORT_FLAG) || defined(__APPLE__))
#define SS_PM_EXPORT_API __attribute__((visibility("default")))
#endif
#endif


#ifndef SS_PM_EXPORT_API
#define SS_PM_EXPORT_API
#endif
