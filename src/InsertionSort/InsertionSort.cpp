//
// Created by wuno on 4/13/19.
//

#include "InsertionSort.h"

std::vector<int> InsertionSort::insertionSort(std::vector<int> &v)  {
    std::cout << "Insertion Sort is Running..." << "\n";
    std::cout << "Insertion Sort [Best: O(N), Worst:O(N^2)]" << "\n";

    // Loop through the length of the collection
    // Start at 1 so we can compare to the last node and move the lowest to the left
    for(int i = 1; i < v.size(); i++) {
        for (int j = 0; j > 0 && v[j] < v[j-1]; ++j) {
            std::swap(v[j], v[j-1]);
            // Remove 1 from j will we get to 0
            // Move the value to the left if it is higher than the previous index
            j--;
        }
    }

    for (auto i : v)
        std::cout << i << ' ';

    std::cout << "\n" << "\n";

    return v;
}