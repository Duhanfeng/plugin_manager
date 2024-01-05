cmake_minimum_required(VERSION 3.8)

project(plugin_manager)

#################################################################################
# 设置C++编译器选项
#################################################################################

set(CMAKE_CXX_STANDARD 14)              # 使用C++14标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # 使用C++
set(CMAKE_INCLUDE_CURRENT_DIR ON)       # 包含当前目录
set(CMAKE_BUILD_TYPE "Release")         # release模式去编译

if (WIN32)
    # 开启此选项,可以在release模式下进行debug调试
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")

else ()
    add_compile_options(-fPIC)
endif ()

#################################################################################
# 第三方库
#################################################################################

#################################################################################
# 系统参数
#################################################################################

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#################################################################################
# 添加工程路径
#################################################################################

set(PROJECT_SOURCES
        include/plugin_manager/plugin.hpp
        include/plugin_manager/plugin_loader.hpp
        src/plugin_loader.cxx
)
add_library(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(
        ${PROJECT_NAME}
        ${Boost_LIBRARIES}
)
