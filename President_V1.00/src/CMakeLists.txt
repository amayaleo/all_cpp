#VERSION := cmake --version
cmake_minimum_required(VERSION 3.9.5)
project(president)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(app  main.cpp)
