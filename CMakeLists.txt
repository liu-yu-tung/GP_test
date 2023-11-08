cmake_minimum_required(VERSION 3.10)
project(gp)

# 將 include 目錄添加到編譯器的一般查找路徑中
include_directories(include)

# 將 src 目錄中的所有源文件添加到變數 SOURCES 中
file(GLOB SOURCES "src/*.cpp")

# 將 main.cpp 和 SOURCES 變數中的源文件編譯成一個名為 YourProjectName 的可執行文件
add_executable(gp main.cpp ${SOURCES})
