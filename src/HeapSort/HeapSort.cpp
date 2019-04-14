//
// Created by wuno on 4/13/19.
//

#include "HeapSort.h"

std::vector<int> HeapSort::heapSort(std::vector<int> &v)  {
    std::cout << "Heap Sort is Running..." << "\n";
    std::cout << "Heap Sort [Best/Average/Worst: O(n log n)]" << "\n";

    int size = v.size();
    int temp;

    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(v, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        heapify(v, i, 0);
    }

    for (auto i : v)
        std::cout << i << ' ';

    std::cout << "\n" << "\n";

    return v;
}

void HeapSort::heapify(std::vector<int> &v, int size, int i) {
    int temp;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && v[l] > v[largest])
        largest = l;
    if (r < size && v[r] > v[largest]) {
        largest = r;
    }
    if (largest != i) {
        temp = v[i];
        v[i] = v[largest];
        v[largest] = temp;
        heapify(v, size, largest);
    }
}
