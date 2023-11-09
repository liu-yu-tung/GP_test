cmake_minimum_required(VERSION 3.10)
project(gp)

add_executable(gp main.cpp)

include_directories(include)

# 將 src 目錄中的所有源文件添加到變數 SOURCES 中
file(GLOB SOURCES "src/*.cpp")
target_sources(gp PRIVATE ${SOURCES})
# 將 main.cpp 和 SOURCES 變數中的源文件編譯成一個名為 YourProjectName 的可執行文件



