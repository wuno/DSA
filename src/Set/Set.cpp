//
// Created by wuno on 4/21/19.
//

#include "Set.h"

Set::Set() {}

Set::~Set() {}

Set::Graph* Set::createGraph(int vertices, int edges, int setData[5][2]) {
    auto graph = new Graph;
    graph->vertices = vertices;
    graph->edges = edges;
    auto *edgeSets = new Edge;
    edgeSets->source = graph->edges;
    edgeSets->destination = sizeof(Edge);
    graph->edgeSets = edgeSets;

    for (int i = 0; i < sizeof(setData - 1); i++) {
        std::cout << "Making Set Edge Source = " << setData[i][0] << " Destination = " << setData[i][1] << "\n";
        graph->edgeSets[i].source = setData[i][0];
        graph->edgeSets[i].destination = setData[i][1];
    }

    isCycle(graph);

    return graph;
}

int Set::findSet(int parent[], int i) {
    if(parent[i] == -1) {
        return i;
    }
    return findSet(parent, parent[i]);
}

void Set::setUnion(int parent[], int x, int y) {
    int xSet = findSet(parent, x);
    int ySet = findSet(parent, y);
    if(xSet != ySet) {
        parent[xSet] = ySet;
    }
}

bool Set::isCycle(Graph *graph) {
    // Allocate memory for creating V subsets
    int *parent = (int*) malloc( graph->vertices * sizeof(int) );

    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->vertices);

    // Iterate through all edges of graph, find subset of both
    // vertices of every edge, if both subsets are same, then
    // there is cycle in graph.
    for(int i = 0; i < graph->edges; ++i) {
        int x = findSet(parent, graph->edgeSets[i].source);
        int y = findSet(parent, graph->edgeSets[i].destination);

        if (x == y) {
            std::cout << "Is Cycle True" << "\n";
            return true;
        }

        setUnion(parent, x, y);
    }
    std::cout << "Is Cycle False" << "\n";
    return false;

}

void Set::printSet() {
    Graph *graph;
    std::cout << "Printing Sets" << "\n";
    for(int i = 0; i < graph->edges; ++i) {
        std::cout << "Graph Vertices = " << graph->vertices << "\n";
        std::cout << "Graph Edges = " << graph->edges << "\n";
        std::cout << "Graph Source = " << graph->edgeSets[i].source << "\n";
        std::cout << "Graph Destination = " << graph->edgeSets[i].destination << "\n";
    }
    std::cout << "\n" << "\n";
}