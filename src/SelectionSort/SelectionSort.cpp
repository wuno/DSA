//
// Created by wuno on 4/13/19.
//

#include "SelectionSort.h"

std::vector<int> SelectionSort::selectionSort(std::vector<int> &v)  {
    std::cout << "Selection Sort is Running..." << "\n";
    std::cout << "Selection Sort [Best/Worst: O(N^2)]" << "\n";

    int length = v.size();
    for (int i = 0; i < length; i++) {

        int min = i;
        for (int j = i; j < length; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        std::swap(v[i], v[min]);
    }

    for (auto i : v)
        std::cout << i << ' ';

    std::cout << "\n" << "\n";

    return v;
}