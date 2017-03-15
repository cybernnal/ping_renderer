cmake_minimum_required(VERSION 3.6)
project(ping)
enable_language(C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast -march=native")

set(SOURCE_FILES
        src/ft_memalloc.c src/render.c src/get_time.c src/init_sdl.c src/lst_tools.c src/process_lst.c src/main.c)

include_directories(includes)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ping_SOURCE_DIR}/cmake")
add_executable(ping ${SOURCE_FILES})
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(ping ${SDL2_LIBRARY} -lm)