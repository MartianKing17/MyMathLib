cmake_minimum_required(VERSION 3.13)
project(MyMathLib)

set(CMAKE_CXX_STANDARD 11)

add_library(MyMathLib SHARED math.cpp math.h Matrix.cpp Matrix.h sort.cpp sort.h List.cpp List.h)