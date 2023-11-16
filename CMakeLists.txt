cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)
project(gp)

# include_directories(include)
file(GLOB GP_SRC "src/*.cpp")

add_executable(gp main.cpp
    ${GP_SRC}
)

target_include_directories(gp PRIVATE
    include
)

# target_sources(gp PRIVATE ${SOURCES})
 



