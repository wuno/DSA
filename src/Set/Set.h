//
// Created by wuno on 4/21/19.
//

#ifndef DSA_SET_H
#define DSA_SET_H
#include <iostream>
#include <array>
#include <string.h>

class Set {
private:

public:
    struct Edge {
        int source;
        int destination;
    };
    struct Graph {
        int vertices;
        int edges;
        Edge *edgeSets;
    };
    Set();
    ~Set();
    Graph* createGraph(int vertices, int edges, int setData[5][2]);
    int findSet(int parent[], int i);
    void setUnion(int parent[], int x, int y);
    bool isCycle(Graph *graph);
    void printSet();
};


#endif //DSA_SET_H
