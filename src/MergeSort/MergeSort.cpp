//
// Created by wuno on 4/13/19.
//

#include "MergeSort.h"

std::vector<int> MergeSort::mergeSort(std::vector<int> &v)  {
    std::cout << "Merge Sort is Running..." << "\n";
    std::cout << "Merge Sort [Best: n(log n), Worst: n(log n)]" << "\n";

    int size = v.size();
    if(size > 1) {
        int mid = size / 2;

        std::vector<int> left(v.begin(), v.begin() + mid);
        std::vector<int> right(v.begin() + mid, v.end());

        mergeSort(left);
        mergeSort(right);

        int l, r = 0;

        // Outer loop the total length of the collection
        for(int i = 0; i < size; i++) {
            int lv = -1;
            int rv = -1;

            if(l < left.size()) {
                lv = left[l];
            }
            if(r < right.size()) {
                rv = right[r];
            }
            if(lv, rv != -1) {
                if(lv < rv) {
                    v[i] = lv;
                    l++;
                }
                if(lv >= rv) {
                    v[i] = lv;
                    r++;
                }
            }
        }

    }

    for (auto i : v)
        std::cout << i << ' ';

    std::cout << "\n" << "\n";

    return v;
}
