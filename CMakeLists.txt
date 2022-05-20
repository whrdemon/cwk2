cmake_minimum_required(VERSION 3.21)
project(cwk2 C)

set(CMAKE_C_STANDARD 11)

include_directories(SDL)

add_executable(cwk2
        main.c
        run.c
        run.h SDL.c SDL.h)

target_link_libraries(cwk2  SDL2)
