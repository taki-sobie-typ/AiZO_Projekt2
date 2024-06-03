//
// Created by ogore on 29.05.2024.
//

#ifndef WEIGHTEDDIRECTEDGRAPHMATRIX_H
#define WEIGHTEDDIRECTEDGRAPHMATRIX_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <unordered_set>

class WeightedDirectedGraphMatrix {
public:
    WeightedDirectedGraphMatrix(int vertices);
    WeightedDirectedGraphMatrix(const WeightedDirectedGraphMatrix& other);
    WeightedDirectedGraphMatrix& operator=(const WeightedDirectedGraphMatrix& other);
    ~WeightedDirectedGraphMatrix();

    void addEdge(int src, int dest, int weight);
    void printGraph() const;
    int getWeight(int src, int dest) const;
    int getSize() const;
    void generateRandomGraph(int density);
    void createSpanningTree();
    int getFirstVertex() const;
    int getLastVertex() const;

private:
    void deepCopy(const WeightedDirectedGraphMatrix& other);
    void clear();

    int vertices;
    std::vector<std::vector<int>> incidentMatrix;
};

#endif // WEIGHTEDDIRECTEDGRAPHMATRIX_H

