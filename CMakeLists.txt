cmake_minimum_required(VERSION 3.13)
project(cpp-niit)

set(CMAKE_CXX_STANDARD 14)

add_executable(t01-00-hello tasks/01/00-hello/main.cpp)

add_executable(s01-io slides/01/io/main.cpp)
add_executable(s01-string slides/01/string/main.cpp)
add_executable(s01-new-delete slides/01/new-delete/main.cpp)
add_executable(s01-refs slides/01/refs/main.cpp)
add_executable(s01-swap slides/01/swap/main.cpp)