cmake_minimum_required(VERSION 2.8)

project(petty_stl)

# in linux should check C++11 support, and define macro to enable some features
if (UNIX)
    add_definitions(-std=c++11)
endif()

#include_directories( 
#)

file(GLOB SOURCES
    src/container/*.*
	src/iterator/*.*
	src/algorithm/*.*
	src/utility/*.*
    src/*.*
)

add_executable(petty_stl_test ${SOURCES})



