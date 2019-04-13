cmake_minimum_required(VERSION 2.8)

project(petty_stl)

# check if support C++11, and define macro to enable some features

#include_directories(
#)

file(GLOB SOURCES
    src/container/*.*
	src/iterator/*.*
	src/algorithm/*.*
    src/*.*
)

add_executable(petty_stl_test ${SOURCES})



