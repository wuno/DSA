//
// Created by wuno on 4/16/19.
//

#ifndef DSA_GRAPH_H
#define DSA_GRAPH_H
#include <iostream>
#include <vector>
#include <string>

class Graph {
private:

public:
    struct NonWeighted {
        int source;
        int destination;
    };
    struct Weighted {
        int source;
        int destination;
        int weight;
    };
    std::vector<std::vector<int>> adjacentList;
    typedef std::pair<int, int> Pair;
    std::vector<std::vector<Pair>> pairsList;
    Graph(std::vector<NonWeighted> const &nonWeighted, std::vector<Weighted> const &weighted);
    void printGraph(Graph const &graph);
};


#endif //DSA_GRAPH_H
