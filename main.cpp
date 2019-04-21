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
#include "src/ShellSort/ShellSort.cpp"
#include "src/HeapSort/HeapSort.cpp"
#include "src/Dictionary/Dictionary.cpp"
#include "src/Graph/Graph.cpp"
#include "src/HashMap/HashMap.cpp"
#include "src/LinkedList/LinkedList.cpp"
#include "src/Queue/Queue.cpp"

int main()
{
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

    // Dijkstra's
    std::vector< std::vector<int> > dijkstraSortVector = {
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
    DijkstraSort dijkstraSort;
    dijkstraSort.dijkstraSort(dijkstraSortVector, 0);

    // Sorting Vector
    std::vector<int> sortingVector = {1, 16, 2, 77, 29, 0, 400, 333, 12, 11, 34, 77};

    // Bubble Sort
    BubbleSort bSort;
    bSort.bubbleSort(sortingVector);

    // Counting Sort
    CountingSort cSort;
    cSort.countingSort(sortingVector);

    // Insertion Sort
    InsertionSort insertionSort;
    insertionSort.insertionSort(sortingVector);

    // Merge Sort
    MergeSort mergeSort;
    mergeSort.mergeSort(sortingVector);

    // Quick Sort
    QuickSort quickSort;
    quickSort.quickSort(sortingVector);

    // Radix Sort
    RadixSort radixSort;
    radixSort.radixSort(sortingVector);

    // Selection Sort
    SelectionSort selectionSort;
    selectionSort.selectionSort(sortingVector);

    // Shell Sort
    ShellSort shellSort;
    shellSort.shellSort(sortingVector);

    // Heap Sort
    HeapSort heapSort;
    heapSort.heapSort(sortingVector);

    // Dictionary
    Dictionary<std::string, std::string> dict;
    dict.insertNode("A", "Apple");
    dict.insertNode("B", "Bumble");
    dict.insertNode("C", "Chair");
    dict.insertNode("D", "Dog");
    dict.insertNode("E", "Eat");
    dict.insertNode("F", "Fool");
    dict.insertNode("G", "Grapes");
    dict.insertNode("H", "House");
    dict.deleteNode("A");
    dict.findNode("C");
    dict.getKeys();
    dict.getValues();

    // Graph
    std::vector<Graph::NonWeighted> nonWeighted = {
            { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
            { 3,2 }, { 4, 5 }, { 5, 4 }
    };
    std::vector<Graph::Weighted> weighted = {
            { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
            { 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
    };
    Graph graph(nonWeighted, weighted);
    graph.printGraph(graph);

    // Hash Map
    int tableSize = 2;
    int key = 10;
    int value = 20;

    HashMap<int, int> hash(tableSize);

    hash.insertHashNode(key, value);
    hash.insertHashNode(333, 444);
    hash.getValue(key);
    hash.deleteValue(key);
    hash.getValue(333);
    hash.getValue(key);
    hash.getCurrentSize();
    hash.getTableSize();
    hash.printHashTable();

    // LinkedList Sort
    LinkedList<int, int> linkedList;
    linkedList.addNode(111, 111);
    linkedList.addNode(222, 222);
    linkedList.addNode(333, 333);
    linkedList.addNode(444, 444);
    linkedList.addNode(555, 555);
    linkedList.addNode(666, 666);
    linkedList.addNode(777, 777);
    linkedList.addNode(888, 888);
    linkedList.getLength();
    linkedList.findNode(555);
    linkedList.deleteNode(222);
    linkedList.deleteNode(333);
    linkedList.deleteNode(444);
    linkedList.deleteNode(555);
    linkedList.deleteNode(666);
    linkedList.deleteNode(999);
    linkedList.findNode(222);
    linkedList.printNodes();

    // Queue
    Queue<int> queue;
    // Testing Add Node
    queue.addNode(1);
    queue.addNode(2);
    queue.addNode(3);
    queue.addNode(4);
    queue.addNode(5);
    queue.addNode(6);
    queue.addNode(7);
    queue.addNode(8);
    queue.addNode(9);
    queue.addNode(10);
    queue.popNode();
    queue.popNode();
    // Testing Remove Node
    queue.removeNode(1);
    queue.removeNode(2);
    queue.removeNode(3);
    queue.removeNode(4);
    queue.removeNode(5);
    queue.removeNode(6);
    queue.removeNode(7);
    queue.removeNode(8);
    queue.removeNode(9);
    queue.removeNode(10);
    // Testing Print Queue
    queue.printQueue();

    return 0;
}