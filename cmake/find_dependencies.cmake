# ----------------------------------------------------------------------------
#   Find Dependencies
# ----------------------------------------------------------------------------

if (NOT WIN32)
    return()
endif ()

message("--------------------------------------------")
message("-")
message("-")
message("-")
message("-")
message("start to find window dependencies....")


if (WIN32)
    set(CUSTOM_LIB_DIR "C:/Program Files/CppLibrary")
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CUSTOM_LIB_DIR}/opencv/build")
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CUSTOM_LIB_DIR}/boost/lib/cmake")
endif ()

set(3rdparty_dir ${CMAKE_SOURCE_DIR}/3rdparty)

message("find local minizip_ng...")
include(cmake/local_lib/find_minizip_ng.cmake)

#message("find local opengl...")
#include(cmake/local_lib/find_glfw.cmake)
#include(cmake/local_lib/find_glad.cmake)
#include(cmake/local_lib/find_glm.cmake)
#include(cmake/local_lib/find_imgui.cmake)
#message("find local eigen...")
#include(cmake/local_lib/find_eigen.cmake)
#message("find local stb...")
#include(cmake/local_lib/find_stb.cmake)
#message("find local fmt...")
#include(cmake/local_lib/find_fmt.cmake)
#message("find local portable_file_dialogs...")
#include(cmake/local_lib/find_portable_file_dialogs.cmake)
#message("find opencv...")
#include(cmake/lib/find_opencv.cmake)
message("find boost...")
include(cmake/lib/find_boost.cmake)
#message("find local nfd...")
#include(cmake/local_lib/find_nativefiledialog_extended.cmake)

message("-")
message("find dependencies finish")

message("-")
message("-")
message("-")
message("-")
message("--------------------------------------------")
