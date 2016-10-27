cmake_minimum_required(VERSION 3.5)
project(psyc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/push_swap.h
        src/dbl.c
        src/init.c
    src/list.c
        src/main.c
    src/ope.c
        src/render.c
        src/sort.c
        )

include_directories(ft_printf/include)
include_directories(include)

add_executable(psyc ${SOURCE_FILES})
