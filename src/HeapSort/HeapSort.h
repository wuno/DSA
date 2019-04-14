//
// Created by wuno on 4/13/19.
//

#ifndef DSA_HEAPSORT_H
#define DSA_HEAPSORT_H
#include <iostream>
#include <vector>

class HeapSort {
private:
    void heapify(std::vector<int> &v, int size, int i);

public:
    std::vector<int> heapSort(std::vector<int> &v);
};

#endif //DSA_HEAPSORT_H
