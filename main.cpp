#include <iostream>
#include "src/BST/BST.cpp"
#include "src/BubbleSort/BubbleSort.cpp"
#include "src/CountingSort/CountingSort.cpp"
#include "src/DijkstraSort/DijkstraSort.cpp"
#include "src/InsertionSort/InsertionSort.cpp"
#include "src/MergeSort/MergeSort.cpp"
#include "src/QuickSort/QuickSort.cpp"
#include "src/RadixSort/RadixSort.cpp"
#include "src/SelectionSort/SelectionSort.cpp"

int main()
{
    // Instantiate a Graph to Work With
    std::vector< std::vector<int> > graph = {
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    // Instantiate a Collection to Work With
    std::vector<int> values = {1, 16, 2, 77, 29, 0, 400, 333, 12, 11, 34, 77};

    // Counting Sort
    CountingSort cSort;
    cSort.countingSort(values);

    // Binary Search Tree (AVL)
    BST<int, int> tree;
    tree.insert(312, 312);
    tree.insert(123, 23);
    tree.insert(133, 133);
    tree.insert(143, 143);
    tree.insert(323, 323);
    tree.insert(543, 543);
    tree.insert(231, 231);
    tree.insert(122, 122);
    tree.insert(432, 432);
    tree.insert(4235, 4235);
    tree.insert(5422, 5422);
    tree.insert(23431, 23431);
    tree.insert(34, 34);
    tree.insert(3412, 3412);
    tree.insert(413, 413);
    tree.insert(5423, 5423);
    tree.insert(6453, 6453);
    tree.insert(234, 234);
    tree.insert(333, 333);
    tree.insert(12, 12);
    tree.printInOrder();
    tree.printPostOrder();
    tree.printPreOrder();
    tree.deleteNode(12);
    tree.deleteNode(34);
    tree.deleteNode(122);
    tree.deleteNode(123);
    tree.deleteNode(133);
    tree.printInOrder();

    // Bubble Sort
    BubbleSort bSort;
    bSort.bubbleSort(values);

    // Dijkstra's Sort
    DijkstraSort dijkstraSort;
    dijkstraSort.dijkstraSort(graph, 0);

    // Insertion Sort
    InsertionSort insertionSort;
    insertionSort.insertionSort(values);

    // Merge Sort
    MergeSort mergeSort;
    mergeSort.mergeSort(values);

    // Quick Sort
    QuickSort quickSort;
    quickSort.quickSort(values);

    // Radix Sort
    RadixSort radixSort;
    radixSort.radixSort(values);

    // Selection Sort
    SelectionSort selectionSort;
    selectionSort.selectionSort(values);

    return 0;
}
