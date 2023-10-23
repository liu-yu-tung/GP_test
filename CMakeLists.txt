cmake_minimum_required(VERSION 3.0)

project(gp)

add_executable(gp main.cpp src/data.cpp)
target_include_directories(gp PRIVATE include/)