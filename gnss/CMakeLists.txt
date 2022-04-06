cmake_minimum_required(VERSION 3.1)

project(Position_Caculate VERSION 1.0)

set (CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_FLAGS "-std=c++17")

include_directories(./include)

aux_source_directory(./src SRC_DIR)

add_executable(Position_Caculate main.cpp ${SRC_DIR})
