cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)
project(gp)

add_executable(gp main.cpp)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

target_sources(gp PRIVATE ${SOURCES})
 



