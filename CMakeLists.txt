cmake_minimum_required(VERSION 3.13)
project(cpp-niit)

set(CMAKE_CXX_STANDARD 14)

add_executable(t01-00-hello tasks/01/00-hello/main.cpp)
add_executable(t01-00_vector tasks/01/00_vector/main.cpp tasks/01/00_vector/vector.cpp)
add_executable(t01-quad tasks/01/quad/main.cpp)
add_executable(t01-05_mystring tasks/01/05_mystring/test.cpp tasks/01/05_mystring/mystring.cpp)
add_executable(t01-06_date tasks/01/06_date/0106.cpp tasks/01/06_date/MyDate.cpp)
add_executable(t04-01_employee tasks/04/employee/0401.cpp tasks/04/employee/Employee.cpp tasks/01/06_date/MyDate.cpp)

add_executable(s01-io slides/01/io/main.cpp)
add_executable(s01-string slides/01/string/main.cpp)
add_executable(s01-new-delete slides/01/new-delete/main.cpp)
add_executable(s01-refs slides/01/refs/main.cpp)
add_executable(s01-swap slides/01/swap/main.cpp)