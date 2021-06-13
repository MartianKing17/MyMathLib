cmake_minimum_required(VERSION 3.13)
project(MyMathLib)

set(CMAKE_CXX_STANDARD 11)

add_library(MyMathLib SHARED math.cpp math.h Matrix.cpp Matrix.h sort.cpp sort.h AVL_Tree.cpp AVL_Tree.h Red_Black_Tree.cpp Red_Black_Tree.h Binary_Tree.cpp Binary_Tree.h Prefix_Tree.cpp Prefix_Tree.h List.cpp List.h)
