//
// Created by wuno on 4/13/19.
//

#include "CountingSort.h"

std::vector<int> CountingSort::countingSort(std::vector<int> &v)  {
    std::cout << "Counting Sort is Running..." << "\n";
    std::cout << "Counting Sort [Best/Avg/Worst: O(N)]" << "\n";

    // Find the largest number in the vector
    int max = 0;
    for (auto i : v) {
        if(i > max) {
            max = i;
        }
    }

    // Create a vector to hold our counted numbers
    std::vector<int> auxiliary(max+1);

    // Place a counter at each index of the value from the original collection
    for (auto i : v)
        auxiliary[i]++;

    // Create a new vector to hold the sorted collection
    std::vector<int> sortedVector;

    // Add the sorted values to the new array, 1 item per counted value at that index
    for(int i = 0; i < auxiliary.size(); i++) {
        while(auxiliary[i] >= 1) {
            sortedVector.push_back(i);
            auxiliary[i]--;
        }
    }

    for (auto i : sortedVector)
        std::cout << i << ' ';

    std::cout << "\n" << "\n";

    return sortedVector;
}
