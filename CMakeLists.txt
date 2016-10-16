cmake_minimum_required(VERSION 3.6)
project(Meth_Prog_Lab_01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp generator.h student.h sort_and_util_alg.h)
add_executable(Meth_Prog_Lab_01 ${SOURCE_FILES})