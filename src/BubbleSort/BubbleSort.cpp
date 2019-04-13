//
// Created by wuno on 4/13/19.
//

#include "BubbleSort.h"

std::vector<int> BubbleSort::bubbleSort(std::vector<int> &v)  {
    std::cout << "Bubble Sort is Running..." << "\n";
    std::cout << "Bubble Sort [Best: O(N), Worst:O(N^2)]" << "\n";

    int l = v.size();

    // Loop through collection and move largest number up
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < l - 1 - i; j++) {
            if(v[j] > v[j+1]) {
                std::swap(v[j], v[j+1]);
            }
        }
    }

    for (auto i : v)
        std::cout << i << ' ';

    std::cout << "\n" << "\n";

    return v;
}

