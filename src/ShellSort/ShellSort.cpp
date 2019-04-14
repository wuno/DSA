//
// Created by wuno on 4/13/19.
//

#include "ShellSort.h"

std::vector<int> ShellSort::shellSort(std::vector<int> &v)  {
    std::cout << "Shell Sort is Running..." << "\n";
    std::cout << "Shell Sort [Best O(n* log n) Worst: O(n* log2n)]" << "\n";

    for(int gap = v.size() / 2; gap >= 1; gap /= 2) {
        for(int i = gap; i < v.size(); i++) {
            int temp = v[i];
            int j = i - gap;
            while(j > 0 && v[j] > temp) {
                v[j + gap] = v[j];
                j = j - gap;
            }
            v[j + gap] = temp;
        }
    }

    for (auto i : v)
        std::cout << i << ' ';

    std::cout << "\n" << "\n";

    return v;
}