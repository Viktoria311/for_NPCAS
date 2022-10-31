cmake_minimum_required(VERSION 3.5)

project(for_NPCAS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(for_NPCAS main.cpp cdarray.h funcs.cpp funcs.h)
