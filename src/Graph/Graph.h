//
// Created by wuno on 4/16/19.
//

#ifndef DSA_GRAPH_H
#define DSA_GRAPH_H
#include <iostream>
#include <vector>

class Graph {
private:

public:
    struct Edge {
        int source;
        int destination;
    };
    std::vector<std::vector<int>> adjacentList;
    Graph(std::vector<Edge> const &edges, int nodes, bool undirected);
    void printGraph(Graph const &graph, int nodes);
};


#endif //DSA_GRAPH_H
