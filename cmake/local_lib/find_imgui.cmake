
# 添加imgui
include_directories(${3rdparty_dir}/imgui/imgui/include)
include_directories(${3rdparty_dir}/imgui/imgui/include/imgui)
file(GLOB_RECURSE imgui_src ${3rdparty_dir}/imgui/imgui/src/*)

# 添加imgui后端(opengl3+glfw)
set(imgui_backends_src
        ${3rdparty_dir}/imgui/imgui_backends/include/imgui_backends/imgui_impl_glfw.h
        ${3rdparty_dir}/imgui/imgui_backends/include/imgui_backends/imgui_impl_opengl3.h
        ${3rdparty_dir}/imgui/imgui_backends/include/imgui_backends/imgui_impl_opengl3_loader.h
        ${3rdparty_dir}/imgui/imgui_backends/src/imgui_impl_glfw.cpp
        ${3rdparty_dir}/imgui/imgui_backends/src/imgui_impl_opengl3.cpp
)
include_directories(${3rdparty_dir}/imgui/imgui_backends/include)
include_directories(${3rdparty_dir}/imgui/imgui_backends/include/imgui_backends)
