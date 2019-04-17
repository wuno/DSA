//
// Created by wuno on 4/16/19.
//

#include "Graph.h"

Graph::Graph(std::vector<Edge> const &edges, int nodes, bool undirected) {
    adjacentList.resize(nodes);
    for(auto &edge: edges) {
        adjacentList[edge.source].push_back(edge.destination);
        if(undirected == true) {
            adjacentList[edge.destination].push_back(edge.source);
        }
    }
}

void Graph::printGraph(Graph const &graph, int nodes) {
    std::cout << "Running Graph..." << "\n";
    for(int i = 0; i < nodes; i++) {
        std::cout << i << " -->";
        for(int v : graph.adjacentList[i]) {
            std::cout << v << " ";
            std::cout << std::endl;
        }
    }
    std::cout << "\n" << "\n";
}