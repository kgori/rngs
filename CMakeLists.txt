cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 23)

project(lcg)

add_executable(lcg main.cpp lib.cpp)
add_executable(sample1 sample1.cpp lib.cpp)
add_executable(sample2 sample2.cpp lib.cpp)
