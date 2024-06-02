//
// Created by Patryk on 31.05.2024.
//

#ifndef DIJKSTRA_SHORTEST_PATH_MATRIX_H
#define DIJKSTRA_SHORTEST_PATH_MATRIX_H

#include "WeightedDirectedGraphMatrix.h"
#include <vector>
#include <limits>

class DijkstraShortestPathMatrix {
public:
    DijkstraShortestPathMatrix(const WeightedDirectedGraphMatrix& graph);

    std::vector<int> findShortestPath(int startVertex, int endVertex);
    void printShortestPath(const std::vector<int>& path) const;

private:
    const WeightedDirectedGraphMatrix& graph;
    std::vector<int> getPath(const std::vector<int>& previous, int startVertex, int endVertex) const;
};

#endif // DIJKSTRA_SHORTEST_PATH_MATRIX_H
