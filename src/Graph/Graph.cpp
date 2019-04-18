//
// Created by wuno on 4/16/19.
//

#include "Graph.h"

Graph::Graph(std::vector<NonWeighted> const &nonWeighted, std::vector<Weighted> const &weighted) {
    int nonWeightedNodes = nonWeighted.size();
    int weightedNodes = weighted.size();

    // Non Weighted
    adjacentList.resize(nonWeightedNodes);
    for(auto &nonweighted : nonWeighted) {
        // For directed non weighted graph
        adjacentList[nonweighted.source].push_back(nonweighted.destination);
        // For undirected non weighed graph
        adjacentList[nonweighted.destination].push_back(nonweighted.source);
    }

    // Weighted
    pairsList.resize(weightedNodes);
    for(auto &withweights : weighted) {
        int source = withweights.source;
        int destination = withweights.destination;
        int weight = withweights.weight;
        // For directed weighted graph
        pairsList[source].push_back(std::make_pair(destination, weight));
        // For undirected weighted graph
        pairsList[destination].push_back(std::make_pair(source, weight));
    }

}

void Graph::printGraph(Graph const &graph) {
    int nonWeightedNodes = graph.adjacentList.size();
    int weightedNodes = graph.pairsList.size();

    std::cout << "\n" << "\n";
    std::cout << "Running Non Weighted Directed Graph..." << "\n";
    for(int i = 0; i < nonWeightedNodes; i++) {
        std::cout << i << " -->";
        for(int v : graph.adjacentList[i]) {
            std::cout << v << " ";
            std::cout << std::endl;
        }
    }

    std::cout << "\n" << "\n";
    std::cout << "Running Weighted Undirected Graph..." << "\n";
    for (int u = 0; u < weightedNodes; u++) {
        std::cout << "Node " << u << " makes an edge with \n";
        for (auto it = graph.pairsList[u].begin(); it!= graph.pairsList[u].end(); it++) {

            std::cout << "\tNode " << it->first << " with edge weight ="
                      << it->second << "\n";
        }
        std::cout << "\n";
    }
    std::cout << "\n" << "\n";
}