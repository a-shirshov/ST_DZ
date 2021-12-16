cmake_minimum_required(VERSION 3.16)

project(STDZ)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_EXE main.cpp)

set(SOURCE_LIB function/function.cpp)

add_library(my_lib STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main my_lib)
