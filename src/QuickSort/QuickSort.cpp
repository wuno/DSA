//
// Created by wuno on 4/13/19.
//

#include "QuickSort.h"

std::vector<int> QuickSort::quickSort(std::vector<int> &v)  {
    std::cout << "Quick Sort is Running..." << "\n";
    std::cout << "Quick Sort [Best: O(N Lg N), Avg: O(N Lg N), Worst:O(N^2)]" << "\n";

    if(v.size() > 1) {
    // Create a pivot point and 2 partitions
    int pivot = v.size() / 2;
    std::vector<int> left;
    std::vector<int> right;

    // Iterate over the collection and sort by appending to the partitions
    for(int i = 0; i < v.size(); i++) {
        if(i != pivot) {
            if(v[i] < v[pivot]) {
                left.push_back(v[i]);
            } else {
                right.push_back(v[i]);
            }
        }
    }

    quickSort(left);
    quickSort(right);

    // Merge the left and right collections back together as a sorted collection
    std::vector<int> sortedVector(v.size() - 1);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), sortedVector.begin());

    for (auto i : sortedVector)
        std::cout << i << ' ';

    std::cout << "\n" << "\n";

    }
    return v;
}