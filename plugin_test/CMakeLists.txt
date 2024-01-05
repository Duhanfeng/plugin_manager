
# 设置打包规则
set(PKG_PLUGIN_DIR ${CMAKE_SOURCE_DIR}/data/plugin)
if (WIN32)
    set(PLUGIN_DLL_HEAD "")
    set(PLUGIN_DLL_EXTENSION "dll")
else ()
    set(PLUGIN_DLL_HEAD "lib")
    set(PLUGIN_DLL_EXTENSION "so")
endif ()
include_directories(${CMAKE_SOURCE_DIR}/plugin_manager/include)

add_subdirectory(plugin_101/node)
add_subdirectory(plugin_101/node_ui)
add_subdirectory(plugin_102/node)
add_subdirectory(plugin_102/node_ui)
add_subdirectory(plugin_103/node)
add_subdirectory(plugin_103/node_ui)