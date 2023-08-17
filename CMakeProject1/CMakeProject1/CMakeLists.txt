cmake_minimum_required(VERSION 3.23)

project(Vector)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

include_directories(${PROJECT_SOURCE_DIR}/CMakeProject1)

add_executable (Vector "Vector.cpp" "Vector.h" "main.cpp" )




