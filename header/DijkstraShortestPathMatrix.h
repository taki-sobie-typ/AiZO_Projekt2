//
// Created by Patryk on 31.05.2024.
//

#ifndef DIJKSTRASHORTESTPATHMATRIX_H
#define DIJKSTRASHORTESTPATHMATRIX_H

#include "WeightedDirectedGraphMatrix.h"
#include <vector>

class DijkstraShortestPathMatrix {
public:
    DijkstraShortestPathMatrix(const WeightedDirectedGraphMatrix& graph);
    std::vector<int> findShortestPath(int startVertex, int endVertex);
    void printShortestPath(const std::vector<int>& path) const;

private:
    std::vector<int> getPath(const std::vector<int>& previous, int startVertex, int endVertex) const;
    const WeightedDirectedGraphMatrix& graph;
};

#endif // DIJKSTRASHORTESTPATHMATRIX_H

