cmake_minimum_required(VERSION 3.16)
project(Problem_Solving)

set(CMAKE_CXX_STANDARD 14)

MATH(EXPR stack_size "1024 * 1024 * 1024") # 1024 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(abc157_E AtCoder/ABC157/abc157_E.cpp)
add_executable(abc170_E AtCoder/ABC170/abc170_E.cpp)