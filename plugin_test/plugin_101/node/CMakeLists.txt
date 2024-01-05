cmake_minimum_required(VERSION 3.8)

project("Plugin.101")

#################################################################################
# 设置C++编译器选项
#################################################################################
#set(BUILD_SHARED_LIBS ON)

#################################################################################
# 第三方库
#################################################################################

#################################################################################
# 系统参数
#################################################################################
add_definitions(-DSS_PLUGIN_EXPORT_FLAG)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#################################################################################
# 添加工程路径
#################################################################################

set(PROJECT_SOURCES
        include/plugin_export.hpp
        src/plugin_export.cxx
)

# 将源代码添加到此项目的可执行文件。
add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCES})
#target_link_libraries(
#        ${PROJECT_NAME}
#        fmt
#        glfw3
#)

####################################################################################################
# 安装
####################################################################################################

####################################################################################################
# 设置生成时的操作
####################################################################################################

if (NOT ${PKG_PLUGIN_DIR} STREQUAL "")
    set(CRT_PKG_PLUGIN_DIR ${PKG_PLUGIN_DIR}/100)
    set(CRT_SRC_DLL ${PROJECT_BINARY_DIR}/${PLUGIN_DLL_HEAD}${PROJECT_NAME}.${PLUGIN_DLL_EXTENSION})
    set(CRT_DST_DLL ${CRT_PKG_PLUGIN_DIR}/${PLUGIN_DLL_HEAD}${PROJECT_NAME}.${PLUGIN_DLL_EXTENSION})
    message(CRT_PKG_PLUGIN_DIR: ${CRT_PKG_PLUGIN_DIR})
    message(CRT_SRC_DLL: ${CRT_SRC_DLL})
    message(CRT_DST_DLL: ${CRT_DST_DLL})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            #拷贝动态链接库到打包路径下
            COMMAND ${CMAKE_COMMAND} -E copy "${CRT_SRC_DLL}" "${CRT_DST_DLL}"
    )
endif ()
