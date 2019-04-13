cmake_minimum_required(VERSION 3.13)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA main.cpp src/BST/BST.cpp src/BST/BST.h src/BubbleSort/BubbleSort.cpp src/BubbleSort/BubbleSort.h src/CountingSort/CountingSort.cpp src/CountingSort/CountingSort.h)