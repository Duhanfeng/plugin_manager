
# 添加minizip-ng
include_directories(${3rdparty_dir}/minizip-ng/include)
link_directories(${3rdparty_dir}/minizip-ng/lib)

set(MINIZIP_LIBS
        bzip2
        liblzma
        libminizip
        zlibstatic
        zstd_static)
message(find minizip_ng finish! MINIZIP_LIBS: ${MINIZIP_LIBS})