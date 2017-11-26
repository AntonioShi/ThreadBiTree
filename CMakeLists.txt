cmake_minimum_required(VERSION 3.8)
project(ThreadBiTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ThreadBinTree.h)
add_executable(ThreadBiTree ${SOURCE_FILES} ThreadBinTree.h)