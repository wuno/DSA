//
// Created by wuno on 4/13/19.
//

#include "DijkstraSort.h"

void DijkstraSort::dijkstraSort(std::vector< std::vector<int> > graph, int src) {
    std::cout << "Dijkstra's Algorithm is Running..." << "\n";
    std::cout << "Dijkstra's Algorithm [Best/Avg/Worst: O(V^2)]" << "\n";

    // Get the size of the graph
    int size = graph.size();
    // Holds the shortest paths
    std::vector<int> distance(size);
    // When index has been added to the tree it is set to true
    std::vector<bool> treeSet(size);

    // Initialize all distances to infinity and treeSet to false
    int infinity = std::numeric_limits<int>::max();
    for(int i = 0; i < size; i++) {
        distance[i] = infinity;
        treeSet[i] = false;
    }

    // Distance of the source vertex from it's self is always 0
    distance[src] = 0;

    // find the shortest path for all vertices
    for(int i = 0; i < size - 1; i++) {
        // Select the minimum distance vertex not yet processed
        int minimumVertex = minDistance(distance, treeSet, size);
        // We are adding the index to the treeSet so set it to true
        treeSet[minimumVertex] = true;

        // Update the distance of the adjacent vertices
        for(int j = 0; j < size; j++) {

            // Only update distance[j] if it is not in the treeSet
            // There is an edge from minimumVertex to j
            // Total weight of the path from src to j through minimumVertex is smaller
            // Than the current value of distance[j]
            if(!treeSet[j] && graph[minimumVertex][j] && distance[minimumVertex] != infinity && distance[minimumVertex] + graph[minimumVertex][j] < distance[j]) {
                distance[j] = distance[minimumVertex] + graph[minimumVertex][j];
            }
        }
    }

    std::cout << "Vertex   Distance from Source" << "\n";
    for (int i = 0; i < size; i++) {
        std::cout << i << "            " << distance[i] << "\n";
    }
    std::cout << "\n" << "\n";

}

int DijkstraSort::minDistance(std::vector<int> distance, std::vector<bool> treeSet, int size) {
    // Initialize min value
    int min = std::numeric_limits<int>::max(), min_index;

    // Find the vertex with the minimum distance value
    // From the set of vertices not yet included in the treeSet
    for (int v = 0; v < size; v++)
        if (treeSet[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}