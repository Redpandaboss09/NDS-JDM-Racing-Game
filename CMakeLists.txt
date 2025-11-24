cmake_minimum_required(VERSION 3.20)

project(jdm_ds_racer C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Pick up all your source files
file(GLOB_RECURSE GAME_SOURCES
        "source/*.c"
        "source/*.h"
)

add_executable(jdm_ds_racer ${GAME_SOURCES}
        source/save_data.h
        source/save_menu.c
        source/menu.c
        source/main_menu.h
        source/save_menu.h)

# Tell CLion/clangd where libnds headers are
target_include_directories(jdm_ds_racer PRIVATE
        "C:/devkitPro/libnds/include"
        "C:/devkitPro/portlibs/nds/include"
)

# Fake the DS defines so completion matches your build
target_compile_definitions(jdm_ds_racer PRIVATE
        ARM9
        NDS
)
