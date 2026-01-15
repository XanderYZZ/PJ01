cmake_minimum_required(VERSION 3.28)

project(PJ01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(PJ01
    src/main.cpp
    src/util.cpp 
    src/list_write.cpp 
    src/list_read.cpp
)