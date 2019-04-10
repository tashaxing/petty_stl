cmake_minimum_required(VERSION 2.8)

project(petty_stl)

#include_directories(
#)

file(GLOB SOURCES 
    src/*.*
)

add_executable(petty_stl_test ${SOURCES})



