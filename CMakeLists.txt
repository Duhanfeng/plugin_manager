cmake_minimum_required(VERSION 3.8)

project(plugin_manager_main)

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

include(cmake/find_dependencies.cmake)


#################################################################################
# 系统参数
#################################################################################


#################################################################################
# 添加工程路径
#################################################################################
add_subdirectory(plugin_manager)
add_subdirectory(plugin_test)
add_subdirectory(tutorials)

#################################################################################
# 打印编译信息
#################################################################################

message(STATUS "CMake ${CMAKE_VERSION} successfully configured ${PROJECT_NAME} using ${CMAKE_GENERATOR} generator")
message(STATUS "${PROJECT_NAME} package version: ${PROJECT_VERSION}")
if (BUILD_SHARED_LIBS)
    message(STATUS "Building dynamic libraries")
else ()
    message(STATUS "Building static libraries")
endif ()
message(STATUS "[cmake] Installation target path: ${CMAKE_INSTALL_PREFIX}")
if (CMAKE_TOOLCHAIN_FILE)
    message(STATUS "[cmake] Use toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
endif ()
message(STATUS "[cmake] Build for OS type:      ${CMAKE_SYSTEM_NAME}")
message(STATUS "[cmake] Build for OS version:   ${CMAKE_SYSTEM_VERSION}")
message(STATUS "[cmake] Build for CPU type:     ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "[cmake] Build type:             ${CMAKE_BUILD_TYPE}")
string(TOUPPER "${CMAKE_BUILD_TYPE}" BUILD_TYPE)
message(STATUS "[cmake] Build with cxx flags:   ${CMAKE_CXX_FLAGS_${BUILD_TYPE}} ${CMAKE_CXX_FLAGS}")
message(STATUS "[cmake] Build with c flags:     ${CMAKE_C_FLAGS_${BUILD_TYPE}} ${CMAKE_C_FLAGS}")

foreach (component ${Snapshoot_COMPONENTS})
    message(STATUS "Building: ${component}")
endforeach ()