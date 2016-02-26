cmake_minimum_required(VERSION 3.3)
project(CStack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wcast-qual")

set(SOURCE_FILES main.cpp CStack.cpp CStack.h)
add_executable(CStack ${SOURCE_FILES})