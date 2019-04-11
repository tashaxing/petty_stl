cmake_minimum_required(VERSION 2.8)

project(petty_stl)

add_compile_options(-std=c++11)

#include_directories(
#)

file(GLOB SOURCES
    src/container/*.*
	src/iterator/*.*
	src/algorithm/*.*
    src/*.*
)

add_executable(petty_stl_test ${SOURCES})



