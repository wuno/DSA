cmake_minimum_required(VERSION 3.13)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA main.cpp src/BST/BST.cpp src/BST/BST.h src/BubbleSort/BubbleSort.cpp src/BubbleSort/BubbleSort.h src/CountingSort/CountingSort.cpp src/CountingSort/CountingSort.h src/DijkstraSort/DijkstraSort.cpp src/DijkstraSort/DijkstraSort.h src/InsertionSort/InsertionSort.cpp src/InsertionSort/InsertionSort.h src/MergeSort/MergeSort.cpp src/MergeSort/MergeSort.h src/QuickSort/QuickSort.cpp src/QuickSort/QuickSort.h src/RadixSort/RadixSort.cpp src/RadixSort/RadixSort.h src/SelectionSort/SelectionSort.cpp src/SelectionSort/SelectionSort.h)