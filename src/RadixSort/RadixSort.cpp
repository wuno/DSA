//
// Created by wuno on 4/13/19.
//

#include "RadixSort.h"

std::vector<int> RadixSort::radixSort(std::vector<int> &v)  {
    std::cout << "Radix Sort is Running..." << "\n";
    std::cout << "Radix Sort [Best/Avg/Worst: O(N)]" << "\n";

    int largestNumber = 0;
    for (auto i : v) {
        if(i > largestNumber) {
            largestNumber = i;
        }
    }
    int size = v.size();
    int significantDigit = 1;
    std::vector<int> auxilory(size - 1);

    // Loop until we reach the largest significant digit
    while(largestNumber/significantDigit > 0) {
        int bucket[10] = {0};

        // Counts the number of "keys" or digits that will go into each bucket
        for (int i = 0; i < size; i++) {
            bucket[(v[i]/significantDigit)%10]++;
        }

        // Add the count of the previous buckets
        // Acquires the indexes after the end of each bucket location in the array
        // Works similar to the count sort algorithm
        for(int i = 1; i < 10; i++) {
            bucket[i] += bucket[i-1];
        }

        // Use the bucket to fill a "auxilory" array
        for (int i = size - 1; i >= 0; i--) {
            bucket[(v[i]/significantDigit)%10]--;
            auxilory[bucket[(v[i]/significantDigit)%10]] = v[i];
        }

        // Replace the current array with the auxilory array
        for (int i = 0; i < size; i++) {
            v[i] = auxilory[i];
        }

        // Move to next significant digit
        significantDigit *= 10;
    }

    for (auto i : v)
        std::cout << i << ' ';

    std::cout << "\n" << "\n";

    return v;
}
