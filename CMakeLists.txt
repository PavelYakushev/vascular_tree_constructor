cmake_minimum_required(VERSION 3.20)
project(vascular_tree_fractalizer)

set(CMAKE_CXX_STANDARD 14)

add_executable(vascular_tree_fractalizer main.cpp Vascular_tree.cpp Vascular_tree.hpp Vascular_tree_node.cpp Vascular_tree_node.hpp space.hpp Predicates.cpp Predicates.hpp constants.hpp space.cpp)
