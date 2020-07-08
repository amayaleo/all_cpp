#VERSION := cmake --version
cmake_minimum_required(VERSION 3.9.5)
project(my_project)
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
#set(CMAKE_CXX_FLAGS "-std=c++17 -stdlib=libc++ ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS " -std=c++17  -Wall -pedantic ${CMAKE_CXX_FLAGS}")
#set_property(TARGET tgt PROPERTY CXX_STANDARD 17)
add_executable(app  main.cpp)

