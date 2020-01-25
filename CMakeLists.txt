cmake_minimum_required(VERSION 3.13)
project(MyMathLib)

set(CMAKE_CXX_STANDARD 11)

add_library(MyMathLib SHARED library.cpp library.h math.cpp math.h Matrix.cpp Matrix.h avl_tree.cpp avl_tree.h sort.cpp sort.h)