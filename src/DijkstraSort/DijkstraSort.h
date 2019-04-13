//
// Created by wuno on 4/13/19.
//

#ifndef DSA_DIJKSTRASORT_H
#define DSA_DIJKSTRASORT_H
#include <iostream>
#include <vector>
#include <limits>

class DijkstraSort {
private:
    int minDistance(std::vector<int> distance, std::vector<bool> treeSet, int size);

public:
    void dijkstraSort(std::vector< std::vector<int> > graph, int src);
};


#endif //DSA_DIJKSTRASORT_H
