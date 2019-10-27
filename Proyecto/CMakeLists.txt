cmake_minimum_required(VERSION 3.13)
project(Caso10 C)

set(CMAKE_C_STANDARD 99)

add_executable(Caso10 main.c cmake-build-debug/matroids.c cmake-build-debug/matroids.h)